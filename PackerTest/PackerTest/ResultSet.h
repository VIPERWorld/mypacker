#pragma once

#include <string>
#include <map>
#include <vector>
#include <list>
#include <stdint.h>

class ResultSet
{
public:
	ResultSet(const char *szResultSetName = "");
	~ResultSet(void);

	// 获取结果集的名称
	const std::string& GetResultSetName() const;

	// 添加新字段
	int AddField(const std::string &strFieldName, char cFieldType = 'S');

	// 添加一行数据
	int AddRow();

	// 通过索引添加数据
	int AddInt32(int nIndex, int32_t nData);
	int AddInt64(int nIndex, int64_t nData);
	int AddDouble(int nIndex, double dData);
	int AddString(int nIndex, const std::string &strData);

	// 通过字段名称添加数据
	int AddInt32(const std::string &strFieldName, int32_t nData);
	int AddInt64(const std::string &strFieldName, int64_t nData);
	int AddDouble(const std::string &strFieldName, double dData);
	int AddString(const std::string &strFieldName, const std::string &strData);

private:
	const char *m_szResultSetName;                        // 结果集名称
	std::map<std::string, int> m_mapFieldIndex;           // 字段的索引位置
	std::vector<std::string> m_vecFields;                 // 字段列表
	std::vector<char> m_vecFieldType;                     // 字段类型
	std::list<std::vector<std::string>* > m_listRows;     // 行数据
	std::vector<std::string> *m_pRowCursor;               // 当前行游标

	char *m_pDataBuf;
};

