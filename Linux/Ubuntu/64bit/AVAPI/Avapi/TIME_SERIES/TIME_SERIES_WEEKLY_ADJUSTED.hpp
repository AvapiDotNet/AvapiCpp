#ifndef TIME_SERIES_WEEKLY_ADJUSTED_HPP_INCLUDED
#define TIME_SERIES_WEEKLY_ADJUSTED_HPP_INCLUDED

#include <string>
#include <map>
#include <list>
#include "../jsmn/jsmn.h"

using namespace std;

namespace Avapi {

class RestClient; //forward declaration

enum class Const_TIME_SERIES_WEEKLY_ADJUSTED_datatype{
    none,
    json,
    csv,
};

class MAP_TIME_SERIES_WEEKLY_ADJUSTED
{
public:
    static const map<Const_TIME_SERIES_WEEKLY_ADJUSTED_datatype, string> s_datatype_translation;
};

class MetaData_Type_TIME_SERIES_WEEKLY_ADJUSTED
{
private:
    string Information;
    string Symbol;
    string LastRefreshed;
    string TimeZone;

public:
    MetaData_Type_TIME_SERIES_WEEKLY_ADJUSTED();
    MetaData_Type_TIME_SERIES_WEEKLY_ADJUSTED(const MetaData_Type_TIME_SERIES_WEEKLY_ADJUSTED& other); // copy constructor
    
    string get_Information() const {return Information;};
    string get_Symbol() const {return Symbol;};
    string get_LastRefreshed() const {return LastRefreshed;};
    string get_TimeZone() const {return TimeZone;};
    void set_Information(string Information){this->Information = Information;};
    void set_Symbol(string Symbol){this->Symbol = Symbol;};
    void set_LastRefreshed(string LastRefreshed){this->LastRefreshed = LastRefreshed;};
    void set_TimeZone(string TimeZone){this->TimeZone = TimeZone;};

    int ParseInternal(string& str_data, jsmntok_t* array_token ,int index, int token_size);
};

class TimeSeries_Type_TIME_SERIES_WEEKLY_ADJUSTED
{
private:
    string Open;
    string High;
    string Low;
    string Close;
    string AdjustedClose;
    string Volume;
    string DividendAmount;
    string DateTime;

public:
    TimeSeries_Type_TIME_SERIES_WEEKLY_ADJUSTED();
    TimeSeries_Type_TIME_SERIES_WEEKLY_ADJUSTED(const TimeSeries_Type_TIME_SERIES_WEEKLY_ADJUSTED& other); // copy constructor

    string get_Open() const {return Open;};
    string get_High() const {return High;};
    string get_Low() const {return Low;};
    string get_Close() const {return Close;};
    string get_AdjustedClose() const {return AdjustedClose;};
    string get_Volume() const {return Volume;};
    string get_DividendAmount() const {return DividendAmount;};
    string get_DateTime() const {return DateTime;};
    void set_Open(string Open){this->Open = Open;};
    void set_High(string High){this->High = High;};
    void set_Low(string Low){this->Low = Low;};
    void set_Close(string Close){this->Close = Close;};
    void set_AdjustedClose(string AdjustedClose){this->AdjustedClose = AdjustedClose;};
    void set_Volume(string Volume){this->Volume = Volume;};
    void set_DividendAmount(string DividendAmount){this->DividendAmount = DividendAmount;};
    void set_DateTime(string DateTime){this->DateTime = DateTime;};
    
   int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class AvapiResponse_TIME_SERIES_WEEKLY_ADJUSTED_Content
{
private:
    MetaData_Type_TIME_SERIES_WEEKLY_ADJUSTED MetaData;
    list<TimeSeries_Type_TIME_SERIES_WEEKLY_ADJUSTED> TimeSeries;
    string str_prefix;
    bool error_status;
    string ErrorMessage;

public:
    AvapiResponse_TIME_SERIES_WEEKLY_ADJUSTED_Content();
    ~AvapiResponse_TIME_SERIES_WEEKLY_ADJUSTED_Content() {};
    AvapiResponse_TIME_SERIES_WEEKLY_ADJUSTED_Content(const AvapiResponse_TIME_SERIES_WEEKLY_ADJUSTED_Content& other); // copy constructor
    MetaData_Type_TIME_SERIES_WEEKLY_ADJUSTED& get_MetaData() {return MetaData;};
    list<TimeSeries_Type_TIME_SERIES_WEEKLY_ADJUSTED>& get_TimeSeries() {return TimeSeries;};
    void set_Error(bool error_status) {this->error_status = error_status;};
    bool isError() {return error_status;};
    string get_ErrorMessage() {return ErrorMessage;};
    void set_ErrorMessage(string ErrorMessage) {this->ErrorMessage = str_prefix + ErrorMessage;};
};

class AvapiResponse_TIME_SERIES_WEEKLY_ADJUSTED
{
private:
    string LastHttpRequest;
    string RawData;
    AvapiResponse_TIME_SERIES_WEEKLY_ADJUSTED_Content* Data;

public:
    AvapiResponse_TIME_SERIES_WEEKLY_ADJUSTED();
    AvapiResponse_TIME_SERIES_WEEKLY_ADJUSTED(const AvapiResponse_TIME_SERIES_WEEKLY_ADJUSTED& other); // copy constructor
    AvapiResponse_TIME_SERIES_WEEKLY_ADJUSTED(AvapiResponse_TIME_SERIES_WEEKLY_ADJUSTED&& other); // move constructor
    AvapiResponse_TIME_SERIES_WEEKLY_ADJUSTED& operator=(const AvapiResponse_TIME_SERIES_WEEKLY_ADJUSTED& other); //copy assignment
    AvapiResponse_TIME_SERIES_WEEKLY_ADJUSTED& operator=(AvapiResponse_TIME_SERIES_WEEKLY_ADJUSTED&& other); //move assignment
    ~AvapiResponse_TIME_SERIES_WEEKLY_ADJUSTED();

    AvapiResponse_TIME_SERIES_WEEKLY_ADJUSTED_Content& get_Data() const {return *Data;};
    string get_LastHttpRequest() const {return LastHttpRequest;};
    string get_RawData() const {return RawData;};
    void set_LastHttpRequest(string LastHttpRequest){this->LastHttpRequest = LastHttpRequest;};
    void set_RawData(string RawData){this->RawData = RawData;};
};

class Impl_TIME_SERIES_WEEKLY_ADJUSTED
{
private:
    string AvapiUrl;
    string ApiKey;
    RestClient *Client;
    static string s_function;
    static Impl_TIME_SERIES_WEEKLY_ADJUSTED *s_instance;
    Impl_TIME_SERIES_WEEKLY_ADJUSTED() {};
    static const unsigned int START_TOKEN_SIZE = 3000;
    static void ParseInternal(AvapiResponse_TIME_SERIES_WEEKLY_ADJUSTED& Response);

public:
    static Impl_TIME_SERIES_WEEKLY_ADJUSTED& getInstance();
    static void destroyInstance();

    string get_AvapiUrl() const {return AvapiUrl;};
    RestClient* get_Client() const {return Client;};
    string get_ApiKey() const {return ApiKey;};
    void set_AvapiUrl(string AvapiUrl){this->AvapiUrl = AvapiUrl;};
    void set_Client(RestClient *Client){this->Client = Client;};
    void set_ApiKey(string ApiKey){this->ApiKey = ApiKey;};

    AvapiResponse_TIME_SERIES_WEEKLY_ADJUSTED Query(string symbol
        ,Const_TIME_SERIES_WEEKLY_ADJUSTED_datatype datatype  = Const_TIME_SERIES_WEEKLY_ADJUSTED_datatype::none
        );

    AvapiResponse_TIME_SERIES_WEEKLY_ADJUSTED Query(string symbol
        ,string datatype  = "json"
        );
};

}//end namespace Avapi

#endif // TIME_SERIES_WEEKLY_ADJUSTED_HPP_INCLUDED
