#include <string>
#include <iostream>
#include <sstream>
#include "Avapi/AvapiConnection.hpp"
#include "Avapi/TECHNICAL_INDICATOR/MACDEXT.hpp"

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
    
    auto& QueryObject = avapi_connection->GetQueryObject_MACDEXT();

    auto Response = QueryObject.Query(   
             "MSFT"
             ,Const_MACDEXT_interval::n_60min
             ,Const_MACDEXT_series_type::close
             ,"16"
             ,"10"
             ,"16"
             ,Const_MACDEXT_fastmatype::n_0
             ,Const_MACDEXT_slowmatype::none
             ,Const_MACDEXT_signalmatype::n_1);

    cout << endl <<  "******** RAW DATA MACDEXT ********"<< endl;
    cout <<  Response.get_RawData() << endl << endl;

    cout << "******** STRUCTURED DATA MACDEXT ********"<< endl;

    if(Response.get_Data().isError())
    {
        cerr << Response.get_Data().get_ErrorMessage() << endl;
    }
    else
    {
        auto& MetaData  = Response.get_Data().get_MetaData();
        auto& TechnicalIndicator = Response.get_Data().get_TechnicalIndicator();

        cout << "========================" << endl;
        cout << "Symbol: " <<  MetaData.get_Symbol() << endl;
        cout << "Indicator: " <<  MetaData.get_Indicator() << endl;
        cout << "LastRefreshed: " <<  MetaData.get_LastRefreshed() << endl;
        cout << "Interval: " <<  MetaData.get_Interval() << endl;
        cout << "FastPeriod: " <<  MetaData.get_FastPeriod() << endl;
        cout << "SlowPeriod: " <<  MetaData.get_SlowPeriod() << endl;
        cout << "SignalPeriod: " <<  MetaData.get_SignalPeriod() << endl;
        cout << "FastMAType: " <<  MetaData.get_FastMAType() << endl;
        cout << "SlowMAType: " <<  MetaData.get_SlowMAType() << endl;
        cout << "SignalMAType: " <<  MetaData.get_SignalMAType() << endl;
        cout << "SeriesType: " <<  MetaData.get_SeriesType() << endl;
        cout << "TimeZone: " <<  MetaData.get_TimeZone() << endl;
        cout << "========================" << endl;
        cout << "========================" << endl;

        for(auto& element : TechnicalIndicator)
        {
            cout << "MACD: " << element.get_MACD() << endl;
            cout << "MACD_Hist: " << element.get_MACD_Hist() << endl;
            cout << "MACD_Signal: " << element.get_MACD_Signal() << endl;
            cout << "DateTime: " << element.get_DateTime() << endl;
            cout << "========================" << endl;
        }
    }
    
	return EXIT_SUCCESS;
}
