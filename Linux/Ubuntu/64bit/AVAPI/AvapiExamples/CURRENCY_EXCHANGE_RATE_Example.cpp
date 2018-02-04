#include <string>
#include <iostream>
#include <sstream>
#include "Avapi/AvapiConnection.hpp"
#include "Avapi/FOREIGN_EXCHANGE/CURRENCY_EXCHANGE_RATE.hpp"

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
    
    auto& QueryObject = avapi_connection->GetQueryObject_CURRENCY_EXCHANGE_RATE();

    auto Response = QueryObject.Query("GBP","EUR");

    cout << endl <<  "******** RAW CURRENCY EXCHANGE RATE ********"<< endl;
    cout <<  Response.get_RawData() << endl << endl;

    cout << "******** STRUCTURED CURRENCY EXCHANGE RATE ********"<< endl;

    if(Response.get_Data().isError())
    {
        cerr << Response.get_Data().get_ErrorMessage() << endl;
    }
    else
    {
        auto& CERate = Response.get_Data().get_CERate();

        cout << "========================" << endl;
        cout << "========================" << endl;

        for(auto& element : CERate)
        {
            cout << "FromCurrencyCode: " << element.get_FromCurrencyCode() << endl;
            cout << "FromCurrencyName: " << element.get_FromCurrencyName() << endl;
            cout << "ToCurrencyCode: " << element.get_ToCurrencyCode() << endl;
            cout << "ToCurrencyName: " << element.get_ToCurrencyName() << endl;
            cout << "ExchangeRate: " << element.get_ExchangeRate() << endl;
            cout << "LastRefreshed: " << element.get_LastRefreshed() << endl;
            cout << "TimeZone: " << element.get_TimeZone() +"\n" ;
            cout << "========================" << endl;
        }
    }
    
	return EXIT_SUCCESS;
}
