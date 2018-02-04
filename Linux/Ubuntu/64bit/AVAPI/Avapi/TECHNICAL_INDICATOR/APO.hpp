#ifndef APO_HPP_INCLUDED
#define APO_HPP_INCLUDED

#include <string>
#include <map>
#include <list>
#include "../jsmn/jsmn.h"

using namespace std;

namespace Avapi {

class RestClient; //forward declaration

enum class Const_APO_interval{
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

enum class Const_APO_series_type{
    none,
    close,
    open,
    high,
    low,
};

enum class Const_APO_matype{
    none,
    n_0,
    n_1,
    n_2,
    n_3,
    n_4,
    n_5,
    n_6,
    n_7,
    n_8,
};

class MAP_APO
{
public:
    static const map<Const_APO_interval, string> s_interval_translation;
    static const map<Const_APO_series_type, string> s_series_type_translation;
    static const map<Const_APO_matype, string> s_matype_translation;
};

class MetaData_Type_APO
{
private:
    string Symbol;
    string Indicator;
    string LastRefreshed;
    string Interval;
    string FastPeriod;
    string SlowPeriod;
    string MAType;
    string SeriesType;
    string TimeZone;

public:
    MetaData_Type_APO();
    MetaData_Type_APO(const MetaData_Type_APO& other); // copy constructor
    
    string get_Symbol() const {return Symbol;};
    string get_Indicator() const {return Indicator;};
    string get_LastRefreshed() const {return LastRefreshed;};
    string get_Interval() const {return Interval;};
    string get_FastPeriod() const {return FastPeriod;};
    string get_SlowPeriod() const {return SlowPeriod;};
    string get_MAType() const {return MAType;};
    string get_SeriesType() const {return SeriesType;};
    string get_TimeZone() const {return TimeZone;};
    void set_Symbol(string Symbol){this->Symbol = Symbol;};
    void set_Indicator(string Indicator){this->Indicator = Indicator;};
    void set_LastRefreshed(string LastRefreshed){this->LastRefreshed = LastRefreshed;};
    void set_Interval(string Interval){this->Interval = Interval;};
    void set_FastPeriod(string FastPeriod){this->FastPeriod = FastPeriod;};
    void set_SlowPeriod(string SlowPeriod){this->SlowPeriod = SlowPeriod;};
    void set_MAType(string MAType){this->MAType = MAType;};
    void set_SeriesType(string SeriesType){this->SeriesType = SeriesType;};
    void set_TimeZone(string TimeZone){this->TimeZone = TimeZone;};

    int ParseInternal(string& str_data, jsmntok_t* array_token ,int index, int token_size);
};

class TechnicalIndicator_Type_APO
{
private:
    string APO;
    string DateTime;

public:
    TechnicalIndicator_Type_APO();
    TechnicalIndicator_Type_APO(const TechnicalIndicator_Type_APO& other); // copy constructor

    string get_APO() const {return APO;};
    string get_DateTime() const {return DateTime;};
    void set_APO(string APO){this->APO = APO;};
    void set_DateTime(string DateTime){this->DateTime = DateTime;};

   int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class AvapiResponse_APO_Content
{
private:
    MetaData_Type_APO MetaData;
    list<TechnicalIndicator_Type_APO> TechnicalIndicator;
    string str_prefix;
    bool error_status;
    string ErrorMessage;

public:
    AvapiResponse_APO_Content();
    ~AvapiResponse_APO_Content() {};
    AvapiResponse_APO_Content(const AvapiResponse_APO_Content& other); // copy constructor
    MetaData_Type_APO& get_MetaData() {return MetaData;};
    list<TechnicalIndicator_Type_APO>& get_TechnicalIndicator() {return TechnicalIndicator;};
    void set_Error(bool error_status) {this->error_status = error_status;};
    bool isError() {return error_status;};
    string get_ErrorMessage() {return ErrorMessage;};
    void set_ErrorMessage(string ErrorMessage) {this->ErrorMessage = str_prefix + ErrorMessage;};
};

class AvapiResponse_APO
{
private:
    string LastHttpRequest;
    string RawData;
    AvapiResponse_APO_Content* Data;

public:
    AvapiResponse_APO();
    AvapiResponse_APO(const AvapiResponse_APO& other); // copy constructor
    AvapiResponse_APO(AvapiResponse_APO&& other); // move constructor
    AvapiResponse_APO& operator=(const AvapiResponse_APO& other); //copy assignment
    AvapiResponse_APO& operator=(AvapiResponse_APO&& other); //move assignment
    ~AvapiResponse_APO();

    AvapiResponse_APO_Content& get_Data() const {return *Data;};
    string get_LastHttpRequest() const {return LastHttpRequest;};
    string get_RawData() const {return RawData;};
    void set_LastHttpRequest(string LastHttpRequest){this->LastHttpRequest = LastHttpRequest;};
    void set_RawData(string RawData){this->RawData = RawData;};
};

class Impl_APO
{
private:
    string AvapiUrl;
    string ApiKey;
    RestClient *Client;
    static string s_function;
    static Impl_APO *s_instance;
    Impl_APO() {};
    static const unsigned int START_TOKEN_SIZE = 3000;
    static void ParseInternal(AvapiResponse_APO& Response);

public:
    static Impl_APO& getInstance();
    static void destroyInstance();

    string get_AvapiUrl() const {return AvapiUrl;};
    RestClient* get_Client() const {return Client;};
    string get_ApiKey() const {return ApiKey;};
    void set_AvapiUrl(string AvapiUrl){this->AvapiUrl = AvapiUrl;};
    void set_Client(RestClient *Client){this->Client = Client;};
    void set_ApiKey(string ApiKey){this->ApiKey = ApiKey;};

    AvapiResponse_APO Query(string symbol
        ,Const_APO_interval interval
        ,Const_APO_series_type series_type
        ,string fastperiod
        ,string slowperiod
        ,Const_APO_matype matype
        );
        
    AvapiResponse_APO Query(string symbol
        ,string interval
        ,string series_type
        ,string fastperiod
        ,string slowperiod
        ,string matype
        );
};

}//end namespace Avapi

#endif // APO_HPP_INCLUDED
