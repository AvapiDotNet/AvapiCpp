#ifndef CMO_HPP_INCLUDED
#define CMO_HPP_INCLUDED

#include <string>
#include <map>
#include <list>
#include "../jsmn/jsmn.h"

using namespace std;

namespace Avapi {

class RestClient; //forward declaration

enum class Const_CMO_interval{
    none,
    n_1min,
    n_5min,
    n_15min,
    n_30min,
    n_60min,
    daily,
    weekly,
    monthly,
};

enum class Const_CMO_series_type{
    none,
    close,
    open,
    high,
    low,
};

class MAP_CMO
{
public:
    static const map<Const_CMO_interval, string> s_interval_translation;
    static const map<Const_CMO_series_type, string> s_series_type_translation;
};

class MetaData_Type_CMO
{
private:
    string Symbol;
    string Indicator;
    string LastRefreshed;
    string Interval;
    string TimePeriod;
    string SeriesType;
    string TimeZone;

public:
    MetaData_Type_CMO();
    MetaData_Type_CMO(const MetaData_Type_CMO& other); // copy constructor
    
    string get_Symbol() const {return Symbol;};
    string get_Indicator() const {return Indicator;};
    string get_LastRefreshed() const {return LastRefreshed;};
    string get_Interval() const {return Interval;};
    string get_TimePeriod() const {return TimePeriod;};
    string get_SeriesType() const {return SeriesType;};
    string get_TimeZone() const {return TimeZone;};
    void set_Symbol(string Symbol){this->Symbol = Symbol;};
    void set_Indicator(string Indicator){this->Indicator = Indicator;};
    void set_LastRefreshed(string LastRefreshed){this->LastRefreshed = LastRefreshed;};
    void set_Interval(string Interval){this->Interval = Interval;};
    void set_TimePeriod(string TimePeriod){this->TimePeriod = TimePeriod;};
    void set_SeriesType(string SeriesType){this->SeriesType = SeriesType;};
    void set_TimeZone(string TimeZone){this->TimeZone = TimeZone;};

    int ParseInternal(string& str_data, jsmntok_t* array_token ,int index, int token_size);
};

class TechnicalIndicator_Type_CMO
{
private:
    string CMO;
    string DateTime;

public:
    TechnicalIndicator_Type_CMO();
    TechnicalIndicator_Type_CMO(const TechnicalIndicator_Type_CMO& other); // copy constructor

    string get_CMO() const {return CMO;};
    string get_DateTime() const {return DateTime;};
    void set_CMO(string CMO){this->CMO = CMO;};
    void set_DateTime(string DateTime){this->DateTime = DateTime;};

   int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class AvapiResponse_CMO_Content
{
private:
    MetaData_Type_CMO MetaData;
    list<TechnicalIndicator_Type_CMO> TechnicalIndicator;
    string str_prefix;
    bool error_status;
    string ErrorMessage;

public:
    AvapiResponse_CMO_Content();
    ~AvapiResponse_CMO_Content() {};
    AvapiResponse_CMO_Content(const AvapiResponse_CMO_Content& other); // copy constructor
    MetaData_Type_CMO& get_MetaData() {return MetaData;};
    list<TechnicalIndicator_Type_CMO>& get_TechnicalIndicator() {return TechnicalIndicator;};
    void set_Error(bool error_status) {this->error_status = error_status;};
    bool isError() {return error_status;};
    string get_ErrorMessage() {return ErrorMessage;};
    void set_ErrorMessage(string ErrorMessage) {this->ErrorMessage = str_prefix + ErrorMessage;};
};

class AvapiResponse_CMO
{
private:
    string LastHttpRequest;
    string RawData;
    AvapiResponse_CMO_Content* Data;

public:
    AvapiResponse_CMO();
    AvapiResponse_CMO(const AvapiResponse_CMO& other); // copy constructor
    AvapiResponse_CMO(AvapiResponse_CMO&& other); // move constructor
    AvapiResponse_CMO& operator=(const AvapiResponse_CMO& other); //copy assignment
    AvapiResponse_CMO& operator=(AvapiResponse_CMO&& other); //move assignment
    ~AvapiResponse_CMO();

    AvapiResponse_CMO_Content& get_Data() const {return *Data;};
    string get_LastHttpRequest() const {return LastHttpRequest;};
    string get_RawData() const {return RawData;};
    void set_LastHttpRequest(string LastHttpRequest){this->LastHttpRequest = LastHttpRequest;};
    void set_RawData(string RawData){this->RawData = RawData;};
};

class Impl_CMO
{
private:
    string AvapiUrl;
    string ApiKey;
    RestClient *Client;
    static string s_function;
    static Impl_CMO *s_instance;
    Impl_CMO() {};
    static const unsigned int START_TOKEN_SIZE = 3000;
    static void ParseInternal(AvapiResponse_CMO& Response);

public:
    static Impl_CMO& getInstance();
    static void destroyInstance();

    string get_AvapiUrl() const {return AvapiUrl;};
    RestClient* get_Client() const {return Client;};
    string get_ApiKey() const {return ApiKey;};
    void set_AvapiUrl(string AvapiUrl){this->AvapiUrl = AvapiUrl;};
    void set_Client(RestClient *Client){this->Client = Client;};
    void set_ApiKey(string ApiKey){this->ApiKey = ApiKey;};

    AvapiResponse_CMO Query(string symbol
        ,Const_CMO_interval interval
        ,string time_period
        ,Const_CMO_series_type series_type
        );
        
    AvapiResponse_CMO Query(string symbol
        ,string interval
        ,string time_period
        ,string series_type
        );
};

}//end namespace Avapi

#endif // CMO_HPP_INCLUDED
