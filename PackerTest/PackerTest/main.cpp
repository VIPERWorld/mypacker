#include <iostream>
#include "ResultSet.h"
#include <ctime>

using namespace std;

int main()
{
	time_t t1 = time(NULL);

	ResultSet rs("test");

	rs.AddField("market", 'I');
	rs.AddField("security_code", 'S');
	rs.AddField("security_name", 'S');
	rs.AddField("security_account", 'S');
	rs.AddField("pre_close_price", 'F');
	rs.AddField("open_price", 'F');
	rs.AddField("last_price", 'F');
	rs.AddField("buy_price1", 'F');
	rs.AddField("buy_amount1", 'I');
	rs.AddField("buy_price2", 'F');
	rs.AddField("buy_amount2", 'I');
	rs.AddField("buy_price3", 'F');
	rs.AddField("buy_amount3", 'I');
	rs.AddField("buy_price4", 'F');
	rs.AddField("buy_amount4", 'I');
	rs.AddField("buy_price5", 'F');
	rs.AddField("buy_amount5", 'I');
	rs.AddField("sell_price1", 'F');
	rs.AddField("sell_amount1", 'I');
	rs.AddField("sell_price2", 'F');
	rs.AddField("sell_amount2", 'I');
	rs.AddField("sell_price3", 'F');
	rs.AddField("sell_amount3", 'I');
	rs.AddField("sell_price4", 'F');
	rs.AddField("sell_amount4", 'I');
	rs.AddField("sell_price5", 'F');
	rs.AddField("sell_amount5", 'I');
	rs.AddField("business_date", 'I');
	rs.AddField("update_time", 'I');

	for (int i=0; i<10000; i++)
	{
		rs.AddRow();

		rs.AddInt32("market", (i%2==0?'0':'1'));
		rs.AddString("security_code", "000000");
		rs.AddString("security_name", "证券名称");
		rs.AddString("security_account", "股东代码");
		rs.AddDouble("pre_close_price", 5.5);
		rs.AddDouble("open_price", 5.1);
		rs.AddDouble("last_price", 5.6);
		rs.AddDouble("buy_price1", 5.5);
		rs.AddInt32("buy_amount1", 100000);
		rs.AddDouble("buy_price2", 5.0);
		rs.AddInt32("buy_amount2", 100000);
		rs.AddDouble("buy_price3", 4.5);
		rs.AddInt32("buy_amount3", 50000);
		rs.AddDouble("buy_price4", 5.5);
		rs.AddInt32("buy_amount4", 40000);
		rs.AddDouble("buy_price5", 8.9);
		rs.AddInt32("buy_amount5", 10000);
		rs.AddDouble("sell_price1", 9.9);
		rs.AddInt32("sell_amount1", 11000);
		rs.AddDouble("sell_price2", 6.6);
		rs.AddInt32("sell_amount2", 10000);
		rs.AddDouble("sell_price3", 8.9);
		rs.AddInt32("sell_amount3", 50000);
		rs.AddDouble("sell_price4", 55.5);
		rs.AddInt32("sell_amount4", 30000);
		rs.AddDouble("sell_price5", 1.1);
		rs.AddInt32("sell_amount5", 899900);
		rs.AddInt32("business_date", 55);
		rs.AddInt32("update_time", 670000);
	}

	time_t t2 = time(NULL);

	cout << t2 - t1 << "S" << endl;

	system("pause");

	return 0;
}