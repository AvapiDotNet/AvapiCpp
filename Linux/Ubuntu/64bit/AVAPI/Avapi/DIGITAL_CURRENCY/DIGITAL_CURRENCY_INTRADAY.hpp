#ifndef DIGITAL_CURRENCY_INTRADAY_HPP_INCLUDED
#define DIGITAL_CURRENCY_INTRADAY_HPP_INCLUDED

#include <string>
#include <map>
#include <list>
#include "../jsmn/jsmn.h"

using namespace std;

namespace Avapi {

class RestClient; //forward declaration

enum class Const_DIGITAL_CURRENCY_INTRADAY_datatype{
    none,
    json,
    csv,
};

class MAP_DIGITAL_CURRENCY_INTRADAY
{
public:
    static const map<Const_DIGITAL_CURRENCY_INTRADAY_datatype, string> s_datatype_translation;
};

class MetaData_Type_DIGITAL_CURRENCY_INTRADAY
{
private:
    string Information;
    string DigitalCurrencyCode;
    string DigitalCurrencyName;
    string MarketCode;
    string MarketName;
    string Interval;
    string LastRefreshed;
    string TimeZone;

public:
    MetaData_Type_DIGITAL_CURRENCY_INTRADAY();
    MetaData_Type_DIGITAL_CURRENCY_INTRADAY(const MetaData_Type_DIGITAL_CURRENCY_INTRADAY& other); // copy constructor

    string get_Information() const {return Information;};
    string get_DigitalCurrencyCode() const {return DigitalCurrencyCode;};
    string get_DigitalCurrencyName() const {return DigitalCurrencyName;};
    string get_MarketCode() const {return MarketCode;};
    string get_MarketName() const {return MarketName;};
    string get_Interval() const {return Interval;};
    string get_LastRefreshed() const {return LastRefreshed;};
    string get_TimeZone() const {return TimeZone;};
    void set_Information(string Information){this->Information = Information;};
    void set_DigitalCurrencyCode(string DigitalCurrencyCode){this->DigitalCurrencyCode = DigitalCurrencyCode;};
    void set_DigitalCurrencyName(string DigitalCurrencyName){this->DigitalCurrencyName = DigitalCurrencyName;};
    void set_MarketCode(string MarketCode){this->MarketCode = MarketCode;};
    void set_MarketName(string MarketName){this->MarketName = MarketName;};
    void set_Interval(string Interval){this->Interval = Interval;};
    void set_LastRefreshed(string LastRefreshed){this->LastRefreshed = LastRefreshed;};
    void set_TimeZone(string TimeZone){this->TimeZone = TimeZone;};

    int ParseInternal(string& str_data, jsmntok_t* array_token ,int index, int token_size);
};



class TimeSeries_Type_DIGITAL_CURRENCY_INTRADAY
{
private:
    string Price;
    string PriceUSD;
    string Volume;
    string MarketCapUSD;
    string DateTime;

public:
    TimeSeries_Type_DIGITAL_CURRENCY_INTRADAY();
    TimeSeries_Type_DIGITAL_CURRENCY_INTRADAY(const TimeSeries_Type_DIGITAL_CURRENCY_INTRADAY& other); // copy constructor

    string get_Price() const {return Price;};
    string get_PriceUSD() const {return PriceUSD;};
    string get_Volume() const {return Volume;};
    string get_MarketCapUSD() const {return MarketCapUSD;};
    string get_DateTime() const {return DateTime;};
    void set_Price(string Price){this->Price = Price;};
    void set_PriceUSD(string PriceUSD){this->PriceUSD = PriceUSD;};
    void set_Volume(string Volume){this->Volume = Volume;};
    void set_MarketCapUSD(string MarketCapUSD){this->MarketCapUSD = MarketCapUSD;};
    void set_DateTime(string DateTime){this->DateTime = DateTime;};

    int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class AvapiResponse_DIGITAL_CURRENCY_INTRADAY_Content
{
private:
    MetaData_Type_DIGITAL_CURRENCY_INTRADAY MetaData;
    list<TimeSeries_Type_DIGITAL_CURRENCY_INTRADAY> TimeSeries;
    string str_prefix;
    bool error_status;
    string ErrorMessage;

public:
    AvapiResponse_DIGITAL_CURRENCY_INTRADAY_Content();
    ~AvapiResponse_DIGITAL_CURRENCY_INTRADAY_Content() {};
    AvapiResponse_DIGITAL_CURRENCY_INTRADAY_Content(const AvapiResponse_DIGITAL_CURRENCY_INTRADAY_Content& other); // copy constructor
    MetaData_Type_DIGITAL_CURRENCY_INTRADAY& get_MetaData() {return MetaData;};
    list<TimeSeries_Type_DIGITAL_CURRENCY_INTRADAY>& get_TimeSeries() {return TimeSeries;};
    void set_Error(bool error_status) {this->error_status = error_status;};
    bool isError() {return error_status;};
    string get_ErrorMessage() {return ErrorMessage;};
    void set_ErrorMessage(string ErrorMessage) {this->ErrorMessage = str_prefix + ErrorMessage;};
};

class AvapiResponse_DIGITAL_CURRENCY_INTRADAY
{
private:
    string LastHttpRequest;
    string RawData;
    AvapiResponse_DIGITAL_CURRENCY_INTRADAY_Content* Data;

public:
    AvapiResponse_DIGITAL_CURRENCY_INTRADAY();
    AvapiResponse_DIGITAL_CURRENCY_INTRADAY(const AvapiResponse_DIGITAL_CURRENCY_INTRADAY& other); // copy constructor
    AvapiResponse_DIGITAL_CURRENCY_INTRADAY(AvapiResponse_DIGITAL_CURRENCY_INTRADAY&& other); // move constructor
    AvapiResponse_DIGITAL_CURRENCY_INTRADAY& operator=(const AvapiResponse_DIGITAL_CURRENCY_INTRADAY& other); //copy assignment
    AvapiResponse_DIGITAL_CURRENCY_INTRADAY& operator=(AvapiResponse_DIGITAL_CURRENCY_INTRADAY&& other); //move assignment
    ~AvapiResponse_DIGITAL_CURRENCY_INTRADAY();

    AvapiResponse_DIGITAL_CURRENCY_INTRADAY_Content& get_Data() const {return *Data;};
    string get_LastHttpRequest() const {return LastHttpRequest;};
    string get_RawData() const {return RawData;};
    void set_LastHttpRequest(string LastHttpRequest){this->LastHttpRequest = LastHttpRequest;};
    void set_RawData(string RawData){this->RawData = RawData;};
};

class Impl_DIGITAL_CURRENCY_INTRADAY
{
private:
    string AvapiUrl;
    string ApiKey;
    RestClient *Client;
    static string s_function;
    static Impl_DIGITAL_CURRENCY_INTRADAY *s_instance;
    Impl_DIGITAL_CURRENCY_INTRADAY() {};
    static const unsigned int START_TOKEN_SIZE = 3000;
    static void ParseInternal(AvapiResponse_DIGITAL_CURRENCY_INTRADAY& Response);

public:
    static Impl_DIGITAL_CURRENCY_INTRADAY& getInstance();
    static void destroyInstance();

    string get_AvapiUrl() const {return AvapiUrl;};
    RestClient* get_Client() const {return Client;};
    string get_ApiKey() const {return ApiKey;};
    void set_AvapiUrl(string AvapiUrl){this->AvapiUrl = AvapiUrl;};
    void set_Client(RestClient *Client){this->Client = Client;};
    void set_ApiKey(string ApiKey){this->ApiKey = ApiKey;};

    AvapiResponse_DIGITAL_CURRENCY_INTRADAY Query(string symbol, string market
        ,Const_DIGITAL_CURRENCY_INTRADAY_datatype datatype  = Const_DIGITAL_CURRENCY_INTRADAY_datatype::none
        );

    AvapiResponse_DIGITAL_CURRENCY_INTRADAY Query(string symbol, string market
        ,string datatype  = ""
        );
};

}//end namespace Avapi

#endif // DIGITAL_CURRENCY_INTRADAY_HPP_INCLUDED
