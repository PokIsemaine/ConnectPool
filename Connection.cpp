//
// Created by zsl on 7/11/22.
//

#include "Connection.hpp"

/**
 * @file Connection
 * @brief 
 * @details 
 * @date 7/11/22
 */
#include "Connection.hpp"
#include "public.hpp"

Connection::Connection() {
    // 初始化数据库连接
    _conn = mysql_init(nullptr);
}

Connection::~Connection() {
    // 释放数据库连接资源
    if(_conn != nullptr) {
        mysql_close(_conn);
    }
}

// 连接数据库
bool Connection::connect(std::string ip, unsigned short port,
                         std::string user,std::string password, std::string dbname) {
    MYSQL *p = mysql_real_connect(_conn, ip.c_str(), user.c_str(),
                                  password.c_str(), dbname.c_str(), port, nullptr, 0);
    return p != nullptr;
}

// 更新操作 insert、delete、update
bool Connection::update(std::string sql)
{
    if (mysql_query(_conn, sql.c_str()))
    {
        LOG("更新失败：" + sql + "\nmysql_error:" + mysql_error(_conn));
        return false;
    }
    return true;
}

// 查询操作 select
MYSQL_RES *Connection::query(std::string sql)
{
    // 查询操作 select
    if (mysql_query(_conn, sql.c_str()))
    {
        LOG("查询失败" + sql + "\nmysql_error:" + mysql_error(_conn));
        return nullptr;
    }
    return mysql_use_result(_conn);
}

// 刷新连接的起始空闲时刻
void Connection::refreshAliveTime()
{
    _alivetime = clock();
}

// 返回连接空闲的时长
clock_t Connection::getAliveTime()
{
    return clock() - _alivetime;
}


