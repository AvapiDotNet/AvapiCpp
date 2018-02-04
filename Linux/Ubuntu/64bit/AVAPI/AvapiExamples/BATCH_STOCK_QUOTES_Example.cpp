#include <string>
#include <iostream>
#include <sstream>
#include "Avapi/AvapiConnection.hpp"
#include "Avapi/TIME_SERIES/BATCH_STOCK_QUOTES.hpp"

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
    
    auto& QueryObject = avapi_connection->GetQueryObject_BATCH_STOCK_QUOTES();

    auto Response = QueryObject.Query(   
             "MSFT,FB,AAPL"
             ,Const_BATCH_STOCK_QUOTES_datatype::json);

    cout << endl <<  "******** RAW DATA BATCH STOCK QUOTES ********"<< endl;
    cout <<  Response.get_RawData() << endl << endl;

    cout << "******** STRUCTURED DATA BATCH STOCK QUOTES ********"<< endl;

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
        cout << "Notes: " <<  MetaData.get_Notes() << endl;
        cout << "TimeZone: " <<  MetaData.get_TimeZone() << endl;
        cout << "========================" << endl;
        cout << "========================" << endl;

        for(auto& element : TimeSeries)
        {
            cout << "Symbol: " << element.get_Symbol() << endl;
            cout << "Price: " << element.get_Price() << endl;
            cout << "Volume: " << element.get_Volume() << endl;
            cout << "TimeStamp: " << element.get_TimeStamp() << endl;
            cout << "========================" << endl;
        }
    }
    
	return EXIT_SUCCESS;
}
