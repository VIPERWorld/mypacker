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

	// ��ȡ�����������
	const std::string& GetResultSetName() const;

	// ������ֶ�
	int AddField(const std::string &strFieldName, char cFieldType = 'S');

	// ���һ������
	int AddRow();

	// ͨ�������������
	int AddInt32(int nIndex, int32_t nData);
	int AddInt64(int nIndex, int64_t nData);
	int AddDouble(int nIndex, double dData);
	int AddString(int nIndex, const std::string &strData);

	// ͨ���ֶ������������
	int AddInt32(const std::string &strFieldName, int32_t nData);
	int AddInt64(const std::string &strFieldName, int64_t nData);
	int AddDouble(const std::string &strFieldName, double dData);
	int AddString(const std::string &strFieldName, const std::string &strData);

private:
	const char *m_szResultSetName;                        // ���������
	std::map<std::string, int> m_mapFieldIndex;           // �ֶε�����λ��
	std::vector<std::string> m_vecFields;                 // �ֶ��б�
	std::vector<char> m_vecFieldType;                     // �ֶ�����
	std::list<std::vector<std::string>* > m_listRows;     // ������
	std::vector<std::string> *m_pRowCursor;               // ��ǰ���α�

	char *m_pDataBuf;
};

