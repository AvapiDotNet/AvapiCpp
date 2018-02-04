#include <string>
#include <iostream>
#include <sstream>
#include "Avapi/AvapiConnection.hpp"
#include "Avapi/DIGITAL_CURRENCY/DIGITAL_CURRENCY_MONTHLY.hpp"

using namespace std;
using namespace Avapi;

int main()
{
    string lastHttpRequest = "";
    AvapiConnection* avapi_connection;
    
    try
    {
        avapi_connection = AvapiConnection::getInstance();
        avapi_connection->set_ApiKey("Your Alpha Vantage API Key !!!!");
    }
    catch(AvapiConnectionError& e)
    {
        cout <<  e.get_error() << endl;
        return EXIT_FAILURE;
    }
    
    auto& QueryObject = avapi_connection->GetQueryObject_DIGITAL_CURRENCY_MONTHLY();

    auto Response = QueryObject.Query(   
             "BTC"
             ,"CNY"
             ,Const_DIGITAL_CURRENCY_MONTHLY_datatype::json);

    cout << endl <<  "******** RAW DATA DIGITAL CURRENCY MONTHLY ********"<< endl;
    cout <<  Response.get_RawData() << endl << endl;

    cout << "******** STRUCTURED DATA DIGITAL CURRENCY MONTHLY ********"<< endl;

    if(Response.get_Data().isError())
    {
        cerr << Response.get_Data().get_ErrorMessage() << endl;
    }
    else
    {
        auto& MetaData  = Response.get_Data().get_MetaData();
        auto& TimeSeries = Response.get_Data().get_TimeSeries();

        cout << "========================" << endl;
        cout << "Information: " <<  MetaData.get_Information() << endl;
        cout << "DigitalCurrencyCode: " <<  MetaData.get_DigitalCurrencyCode() << endl;
        cout << "DigitalCurrencyName: " <<  MetaData.get_DigitalCurrencyName() << endl;
        cout << "MarketCode: " <<  MetaData.get_MarketCode() << endl;
        cout << "MarketName: " <<  MetaData.get_MarketName() << endl;
        cout << "LastRefreshed: " <<  MetaData.get_LastRefreshed() << endl;
        cout << "TimeZone: " <<  MetaData.get_TimeZone() << endl;
        cout << "========================" << endl;
        cout << "========================" << endl;

        for(auto& element : TimeSeries)
        {
            cout << "Open: " << element.get_Open() << endl;
            cout << "OpenUSD: " << element.get_OpenUSD() << endl;
            cout << "High: " << element.get_High() << endl;
            cout << "HighUSD: " << element.get_HighUSD() << endl;
            cout << "Low: " << element.get_Low() << endl;
            cout << "LowUSD: " << element.get_LowUSD() << endl;
            cout << "Close: " << element.get_Close() << endl;
            cout << "CloseUSD: " << element.get_CloseUSD() << endl;
            cout << "Volume: " << element.get_Volume() << endl;
            cout << "MarketCapUSD: " << element.get_MarketCapUSD() << endl;
            cout << "DateTime: " << element.get_DateTime() << endl;
            cout << "========================" << endl;
        }
    }
    
	return EXIT_SUCCESS;
}
