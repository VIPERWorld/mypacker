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

	// ����һ����ΪszResultSetName�Ľ����
	int NewResultSet(const std::string &strResultSetName);

private:
	std::vector<ResultSet*> m_vecResultSet;          // ������б�
	std::map<std::string, int> m_mapResultSetIndex;  // ���������
	ResultSet *m_pResultSetCursor;                   // ��ǰ������α�
};

