#include <string>
#include <iostream>
#include <sstream>
#include "Avapi/AvapiConnection.hpp"
#include "Avapi/TIME_SERIES/TIME_SERIES_WEEKLY_ADJUSTED.hpp"

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
    
    auto& QueryObject = avapi_connection->GetQueryObject_TIME_SERIES_WEEKLY_ADJUSTED();

    auto Response = QueryObject.Query(   
             "MSFT"
             ,Const_TIME_SERIES_WEEKLY_ADJUSTED_datatype::json);

    cout << endl <<  "******** RAW DATA TIME SERIES WEEKLY ADJUSTED ********"<< endl;
    cout <<  Response.get_RawData() << endl << endl;

    cout << "******** STRUCTURED DATA TIME SERIES WEEKLY ADJUSTED ********"<< endl;

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
        cout << "Symbol: " <<  MetaData.get_Symbol() << endl;
        cout << "LastRefreshed: " <<  MetaData.get_LastRefreshed() << endl;
        cout << "TimeZone: " <<  MetaData.get_TimeZone() << endl;
        cout << "========================" << endl;
        cout << "========================" << endl;

        for(auto& element : TimeSeries)
        {
            cout << "Open: " << element.get_Open() << endl;
            cout << "High: " << element.get_High() << endl;
            cout << "Low: " << element.get_Low() << endl;
            cout << "Close: " << element.get_Close() << endl;
            cout << "AdjustedClose: " << element.get_AdjustedClose() << endl;
            cout << "Volume: " << element.get_Volume() << endl;
            cout << "DividendAmount: " << element.get_DividendAmount() << endl;
            cout << "DateTime: " << element.get_DateTime() << endl;
            cout << "========================" << endl;
        }
    }
    
	return EXIT_SUCCESS;
}
