#include "IPacker.h"
#include "ResultSet.h"


IPacker::IPacker(void)
	: m_pResultSetCursor(NULL)
{
}


IPacker::~IPacker(void)
{
}

int IPacker::NewResultSet( const std::string &strResultSetName )
{
	// 同名结果集已经存在
	if (m_mapResultSetIndex.find(strResultSetName) != m_mapResultSetIndex.end())
	{
		return -1;
	}

	m_pResultSetCursor = new ResultSet(strResultSetName);

	m_vecResultSet.push_back(m_pResultSetCursor);
	int index = m_mapResultSetIndex.size();
	m_mapResultSetIndex[strResultSetName] = index;

	return index;
}
