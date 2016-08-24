#pragma once

#include <string>
#include <map>
#include <vector>
#include <list>

class ResultSet;

class IPacker
{
public:
	IPacker(void);
	~IPacker(void);

	// 构造一个名为szResultSetName的结果集
	int NewResultSet(const std::string &strResultSetName);

private:
	std::vector<ResultSet*> m_vecResultSet;          // 结果集列表
	std::map<std::string, int> m_mapResultSetIndex;  // 结果集索引
	ResultSet *m_pResultSetCursor;                   // 当前结果集游标
};

