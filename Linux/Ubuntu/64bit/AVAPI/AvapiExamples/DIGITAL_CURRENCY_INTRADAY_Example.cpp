#include <string>
#include <iostream>
#include <sstream>
#include "Avapi/AvapiConnection.hpp"
#include "Avapi/DIGITAL_CURRENCY/DIGITAL_CURRENCY_INTRADAY.hpp"

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
    
    auto& QueryObject = avapi_connection->GetQueryObject_DIGITAL_CURRENCY_INTRADAY();

    auto Response = QueryObject.Query(   
             "BTC"
             ,"CNY"
             ,Const_DIGITAL_CURRENCY_INTRADAY_datatype::json);

    cout << endl <<  "******** RAW DATA DIGITAL CURRENCY INTRADAY ********"<< endl;
    cout <<  Response.get_RawData() << endl << endl;

    cout << "******** STRUCTURED DATA DIGITAL CURRENCY INTRADAY ********"<< endl;

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
        cout << "Interval: " <<  MetaData.get_Interval() << endl;
        cout << "LastRefreshed: " <<  MetaData.get_LastRefreshed() << endl;
        cout << "TimeZone: " <<  MetaData.get_TimeZone() << endl;
        cout << "========================" << endl;
        cout << "========================" << endl;

        for(auto& element : TimeSeries)
        {
            cout << "Price: " << element.get_Price() << endl;
            cout << "PriceUSD: " << element.get_PriceUSD() << endl;
            cout << "Volume: " << element.get_Volume() << endl;
            cout << "MarketCapUSD: " << element.get_MarketCapUSD() << endl;
            cout << "DateTime: " << element.get_DateTime() << endl;
            cout << "========================" << endl;
        }
    }
    
	return EXIT_SUCCESS;
}
