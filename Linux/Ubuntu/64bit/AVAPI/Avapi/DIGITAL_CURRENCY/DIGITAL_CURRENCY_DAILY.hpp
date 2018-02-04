#ifndef DIGITAL_CURRENCY_DAILY_HPP_INCLUDED
#define DIGITAL_CURRENCY_DAILY_HPP_INCLUDED

#include <string>
#include <map>
#include <list>
#include "../jsmn/jsmn.h"

using namespace std;

namespace Avapi {

class RestClient; //forward declaration

enum class Const_DIGITAL_CURRENCY_DAILY_datatype{
    none,
    json,
    csv,
};

class MAP_DIGITAL_CURRENCY_DAILY
{
public:
    static const map<Const_DIGITAL_CURRENCY_DAILY_datatype, string> s_datatype_translation;
};

class MetaData_Type_DIGITAL_CURRENCY_DAILY
{
private:
    string Information;
    string DigitalCurrencyCode;
    string DigitalCurrencyName;
    string MarketCode;
    string MarketName;
    string LastRefreshed;
    string TimeZone;

public:
    MetaData_Type_DIGITAL_CURRENCY_DAILY();
    MetaData_Type_DIGITAL_CURRENCY_DAILY(const MetaData_Type_DIGITAL_CURRENCY_DAILY& other); // copy constructor

    string get_Information() const {return Information;};
    string get_DigitalCurrencyCode() const {return DigitalCurrencyCode;};
    string get_DigitalCurrencyName() const {return DigitalCurrencyName;};
    string get_MarketCode() const {return MarketCode;};
    string get_MarketName() const {return MarketName;};
    string get_LastRefreshed() const {return LastRefreshed;};
    string get_TimeZone() const {return TimeZone;};
    void set_Information(string Information){this->Information = Information;};
    void set_DigitalCurrencyCode(string DigitalCurrencyCode){this->DigitalCurrencyCode = DigitalCurrencyCode;};
    void set_DigitalCurrencyName(string DigitalCurrencyName){this->DigitalCurrencyName = DigitalCurrencyName;};
    void set_MarketCode(string MarketCode){this->MarketCode = MarketCode;};
    void set_MarketName(string MarketName){this->MarketName = MarketName;};
    void set_LastRefreshed(string LastRefreshed){this->LastRefreshed = LastRefreshed;};
    void set_TimeZone(string TimeZone){this->TimeZone = TimeZone;};

    int ParseInternal(string& str_data, jsmntok_t* array_token ,int index, int token_size);
};



class TimeSeries_Type_DIGITAL_CURRENCY_DAILY
{
private:
    string Open;
    string OpenUSD;
    string High;
    string HighUSD;
    string Low;
    string LowUSD;
    string Close;
    string CloseUSD;
    string Volume;
    string MarketCapUSD;
    string DateTime;

public:
    TimeSeries_Type_DIGITAL_CURRENCY_DAILY();
    TimeSeries_Type_DIGITAL_CURRENCY_DAILY(const TimeSeries_Type_DIGITAL_CURRENCY_DAILY& other); // copy constructor

    string get_Open() const {return Open;};
    string get_OpenUSD() const {return OpenUSD;};
    string get_High() const {return High;};
    string get_HighUSD() const {return HighUSD;};
    string get_Low() const {return Low;};
    string get_LowUSD() const {return LowUSD;};
    string get_Close() const {return Close;};
    string get_CloseUSD() const {return CloseUSD;};
    string get_Volume() const {return Volume;};
    string get_MarketCapUSD() const {return MarketCapUSD;};
    string get_DateTime() const {return DateTime;};
    void set_Open(string Open){this->Open = Open;};
    void set_OpenUSD(string OpenUSD){this->OpenUSD = OpenUSD;};
    void set_High(string High){this->High = High;};
    void set_HighUSD(string HighUSD){this->HighUSD = HighUSD;};
    void set_Low(string Low){this->Low = Low;};
    void set_LowUSD(string LowUSD){this->LowUSD = LowUSD;};
    void set_Close(string Close){this->Close = Close;};
    void set_CloseUSD(string CloseUSD){this->CloseUSD = CloseUSD;};
    void set_Volume(string Volume){this->Volume = Volume;};
    void set_MarketCapUSD(string MarketCapUSD){this->MarketCapUSD = MarketCapUSD;};
    void set_DateTime(string DateTime){this->DateTime = DateTime;};

    int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class AvapiResponse_DIGITAL_CURRENCY_DAILY_Content
{
private:
    MetaData_Type_DIGITAL_CURRENCY_DAILY MetaData;
    list<TimeSeries_Type_DIGITAL_CURRENCY_DAILY> TimeSeries;
    string str_prefix;
    bool error_status;
    string ErrorMessage;

public:
    AvapiResponse_DIGITAL_CURRENCY_DAILY_Content();
    ~AvapiResponse_DIGITAL_CURRENCY_DAILY_Content() {};
    AvapiResponse_DIGITAL_CURRENCY_DAILY_Content(const AvapiResponse_DIGITAL_CURRENCY_DAILY_Content& other); // copy constructor
    MetaData_Type_DIGITAL_CURRENCY_DAILY& get_MetaData() {return MetaData;};
    list<TimeSeries_Type_DIGITAL_CURRENCY_DAILY>& get_TimeSeries() {return TimeSeries;};
    void set_Error(bool error_status) {this->error_status = error_status;};
    bool isError() {return error_status;};
    string get_ErrorMessage() {return ErrorMessage;};
    void set_ErrorMessage(string ErrorMessage) {this->ErrorMessage = str_prefix + ErrorMessage;};
};

class AvapiResponse_DIGITAL_CURRENCY_DAILY
{
private:
    string LastHttpRequest;
    string RawData;
    AvapiResponse_DIGITAL_CURRENCY_DAILY_Content* Data;

public:
    AvapiResponse_DIGITAL_CURRENCY_DAILY();
    AvapiResponse_DIGITAL_CURRENCY_DAILY(const AvapiResponse_DIGITAL_CURRENCY_DAILY& other); // copy constructor
    AvapiResponse_DIGITAL_CURRENCY_DAILY(AvapiResponse_DIGITAL_CURRENCY_DAILY&& other); // move constructor
    AvapiResponse_DIGITAL_CURRENCY_DAILY& operator=(const AvapiResponse_DIGITAL_CURRENCY_DAILY& other); //copy assignment
    AvapiResponse_DIGITAL_CURRENCY_DAILY& operator=(AvapiResponse_DIGITAL_CURRENCY_DAILY&& other); //move assignment
    ~AvapiResponse_DIGITAL_CURRENCY_DAILY();

    AvapiResponse_DIGITAL_CURRENCY_DAILY_Content& get_Data() const {return *Data;};
    string get_LastHttpRequest() const {return LastHttpRequest;};
    string get_RawData() const {return RawData;};
    void set_LastHttpRequest(string LastHttpRequest){this->LastHttpRequest = LastHttpRequest;};
    void set_RawData(string RawData){this->RawData = RawData;};
};

class Impl_DIGITAL_CURRENCY_DAILY
{
private:
    string AvapiUrl;
    string ApiKey;
    RestClient *Client;
    static string s_function;
    static Impl_DIGITAL_CURRENCY_DAILY *s_instance;
    Impl_DIGITAL_CURRENCY_DAILY() {};
    static const unsigned int START_TOKEN_SIZE = 3000;
    static void ParseInternal(AvapiResponse_DIGITAL_CURRENCY_DAILY& Response);

public:
    static Impl_DIGITAL_CURRENCY_DAILY& getInstance();
    static void destroyInstance();

    string get_AvapiUrl() const {return AvapiUrl;};
    RestClient* get_Client() const {return Client;};
    string get_ApiKey() const {return ApiKey;};
    void set_AvapiUrl(string AvapiUrl){this->AvapiUrl = AvapiUrl;};
    void set_Client(RestClient *Client){this->Client = Client;};
    void set_ApiKey(string ApiKey){this->ApiKey = ApiKey;};

    AvapiResponse_DIGITAL_CURRENCY_DAILY Query(string symbol, string market
        ,Const_DIGITAL_CURRENCY_DAILY_datatype datatype  = Const_DIGITAL_CURRENCY_DAILY_datatype::none
        );

    AvapiResponse_DIGITAL_CURRENCY_DAILY Query(string symbol, string market
        ,string datatype  = ""
        );
};

}//end namespace Avapi

#endif // DIGITAL_CURRENCY_DAILY_HPP_INCLUDED
