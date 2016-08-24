#include "ResultSet.h"
#include "helper.h"

ResultSet::ResultSet(const char *szResultSetName)
	: m_pRowCursor(NULL)
{
	m_pDataBuf = (char *)malloc(4096);
	m_szResultSetName = m_pDataBuf;
}


ResultSet::~ResultSet(void)
{
	// 释放内存
	std::list<std::vector<std::string>* >::iterator itor = m_listRows.begin();
	while (itor != m_listRows.end())
	{
		delete (*itor);
		itor++;
	}
}

const std::string& ResultSet::GetResultSetName() const
{
	return m_strResultSetName;
}

int ResultSet::AddField( const std::string &strFieldName, char cFieldType /*= 'S'*/ )
{
	// 已经存在
	if (m_mapFieldIndex.find(strFieldName) != m_mapFieldIndex.end())
	{
		return -1;
	}

	int index = m_mapFieldIndex.size();
	m_mapFieldIndex[strFieldName] = index;
	m_vecFields.push_back(strFieldName);
	m_vecFieldType.push_back(cFieldType);

	return index;
}

int ResultSet::AddRow()
{
	std::vector<std::string> *pVecRow = new std::vector<std::string>(m_vecFields.size(), "");
	m_listRows.push_back(pVecRow);
	m_pRowCursor = pVecRow;

	return m_listRows.size();
}

int ResultSet::AddInt32( int nIndex, int32_t nData )
{
	if (nIndex < 0 || !m_pRowCursor || nIndex > m_pRowCursor->size())
	{
		return -1;
	}

	m_pRowCursor->at(nIndex) = i32toa(nData);
	return 0;
}

int ResultSet::AddInt32( const std::string &strFieldName, int32_t nData )
{
	std::map<std::string, int>::iterator itor = m_mapFieldIndex.find(strFieldName);
	if (itor == m_mapFieldIndex.end())
	{
		return -1;
	}

	m_pRowCursor->at(itor->second) = i32toa(nData);
	return 0;
}

int ResultSet::AddInt64( int nIndex, int64_t nData )
{
	if (nIndex < 0 || !m_pRowCursor || nIndex > m_pRowCursor->size())
	{
		return -1;
	}

	m_pRowCursor->at(nIndex) = i64toa(nData);
	return 0;
}

int ResultSet::AddInt64( const std::string &strFieldName, int64_t nData )
{
	std::map<std::string, int>::iterator itor = m_mapFieldIndex.find(strFieldName);
	if (itor == m_mapFieldIndex.end())
	{
		return -1;
	}

	m_pRowCursor->at(itor->second) = i64toa(nData);
	return 0;
}

int ResultSet::AddDouble( int nIndex, double dData )
{
	if (nIndex < 0 || !m_pRowCursor || nIndex > m_pRowCursor->size())
	{
		return -1;
	}

	m_pRowCursor->at(nIndex) = dtoa(dData);
	return 0;
}

int ResultSet::AddDouble( const std::string &strFieldName, double dData )
{
	std::map<std::string, int>::iterator itor = m_mapFieldIndex.find(strFieldName);
	if (itor == m_mapFieldIndex.end())
	{
		return -1;
	}

	m_pRowCursor->at(itor->second) = dtoa(dData);
	return 0;
}

int ResultSet::AddString( int nIndex, const std::string &strData )
{
	if (nIndex < 0 || !m_pRowCursor || nIndex > m_pRowCursor->size())
	{
		return -1;
	}

	m_pRowCursor->at(nIndex) = strData;
	return 0;
}

int ResultSet::AddString( const std::string &strFieldName, const std::string &strData )
{
	std::map<std::string, int>::iterator itor = m_mapFieldIndex.find(strFieldName);
	if (itor == m_mapFieldIndex.end())
	{
		return -1;
	}

	m_pRowCursor->at(itor->second) = strData;
	return 0;
}
