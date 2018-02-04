#ifndef STOCH_HPP_INCLUDED
#define STOCH_HPP_INCLUDED

#include <string>
#include <map>
#include <list>
#include "../jsmn/jsmn.h"

using namespace std;

namespace Avapi {

class RestClient; //forward declaration

enum class Const_STOCH_interval{
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

enum class Const_STOCH_slowkmatype{
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

enum class Const_STOCH_slowdmatype{
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

class MAP_STOCH
{
public:
    static const map<Const_STOCH_interval, string> s_interval_translation;
    static const map<Const_STOCH_slowkmatype, string> s_slowkmatype_translation;
    static const map<Const_STOCH_slowdmatype, string> s_slowdmatype_translation;
};

class MetaData_Type_STOCH
{
private:
    string Symbol;
    string Indicator;
    string LastRefreshed;
    string Interval;
    string FastKPeriod;
    string SlowKPeriod;
    string SlowKMAType;
    string SlowDPeriod;
    string SlowDMAType;
    string TimeZone;

public:
    MetaData_Type_STOCH();
    MetaData_Type_STOCH(const MetaData_Type_STOCH& other); // copy constructor
    
    string get_Symbol() const {return Symbol;};
    string get_Indicator() const {return Indicator;};
    string get_LastRefreshed() const {return LastRefreshed;};
    string get_Interval() const {return Interval;};
    string get_FastKPeriod() const {return FastKPeriod;};
    string get_SlowKPeriod() const {return SlowKPeriod;};
    string get_SlowKMAType() const {return SlowKMAType;};
    string get_SlowDPeriod() const {return SlowDPeriod;};
    string get_SlowDMAType() const {return SlowDMAType;};
    string get_TimeZone() const {return TimeZone;};
    void set_Symbol(string Symbol){this->Symbol = Symbol;};
    void set_Indicator(string Indicator){this->Indicator = Indicator;};
    void set_LastRefreshed(string LastRefreshed){this->LastRefreshed = LastRefreshed;};
    void set_Interval(string Interval){this->Interval = Interval;};
    void set_FastKPeriod(string FastKPeriod){this->FastKPeriod = FastKPeriod;};
    void set_SlowKPeriod(string SlowKPeriod){this->SlowKPeriod = SlowKPeriod;};
    void set_SlowKMAType(string SlowKMAType){this->SlowKMAType = SlowKMAType;};
    void set_SlowDPeriod(string SlowDPeriod){this->SlowDPeriod = SlowDPeriod;};
    void set_SlowDMAType(string SlowDMAType){this->SlowDMAType = SlowDMAType;};
    void set_TimeZone(string TimeZone){this->TimeZone = TimeZone;};

    int ParseInternal(string& str_data, jsmntok_t* array_token ,int index, int token_size);
};

class TechnicalIndicator_Type_STOCH
{
private:
    string SlowK;
    string SlowD;
    string DateTime;

public:
    TechnicalIndicator_Type_STOCH();
    TechnicalIndicator_Type_STOCH(const TechnicalIndicator_Type_STOCH& other); // copy constructor

    string get_SlowK() const {return SlowK;};
    string get_SlowD() const {return SlowD;};
    string get_DateTime() const {return DateTime;};
    void set_SlowK(string SlowK){this->SlowK = SlowK;};
    void set_SlowD(string SlowD){this->SlowD = SlowD;};
    void set_DateTime(string DateTime){this->DateTime = DateTime;};

   int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class AvapiResponse_STOCH_Content
{
private:
    MetaData_Type_STOCH MetaData;
    list<TechnicalIndicator_Type_STOCH> TechnicalIndicator;
    string str_prefix;
    bool error_status;
    string ErrorMessage;

public:
    AvapiResponse_STOCH_Content();
    ~AvapiResponse_STOCH_Content() {};
    AvapiResponse_STOCH_Content(const AvapiResponse_STOCH_Content& other); // copy constructor
    MetaData_Type_STOCH& get_MetaData() {return MetaData;};
    list<TechnicalIndicator_Type_STOCH>& get_TechnicalIndicator() {return TechnicalIndicator;};
    void set_Error(bool error_status) {this->error_status = error_status;};
    bool isError() {return error_status;};
    string get_ErrorMessage() {return ErrorMessage;};
    void set_ErrorMessage(string ErrorMessage) {this->ErrorMessage = str_prefix + ErrorMessage;};
};

class AvapiResponse_STOCH
{
private:
    string LastHttpRequest;
    string RawData;
    AvapiResponse_STOCH_Content* Data;

public:
    AvapiResponse_STOCH();
    AvapiResponse_STOCH(const AvapiResponse_STOCH& other); // copy constructor
    AvapiResponse_STOCH(AvapiResponse_STOCH&& other); // move constructor
    AvapiResponse_STOCH& operator=(const AvapiResponse_STOCH& other); //copy assignment
    AvapiResponse_STOCH& operator=(AvapiResponse_STOCH&& other); //move assignment
    ~AvapiResponse_STOCH();

    AvapiResponse_STOCH_Content& get_Data() const {return *Data;};
    string get_LastHttpRequest() const {return LastHttpRequest;};
    string get_RawData() const {return RawData;};
    void set_LastHttpRequest(string LastHttpRequest){this->LastHttpRequest = LastHttpRequest;};
    void set_RawData(string RawData){this->RawData = RawData;};
};

class Impl_STOCH
{
private:
    string AvapiUrl;
    string ApiKey;
    RestClient *Client;
    static string s_function;
    static Impl_STOCH *s_instance;
    Impl_STOCH() {};
    static const unsigned int START_TOKEN_SIZE = 3000;
    static void ParseInternal(AvapiResponse_STOCH& Response);

public:
    static Impl_STOCH& getInstance();
    static void destroyInstance();

    string get_AvapiUrl() const {return AvapiUrl;};
    RestClient* get_Client() const {return Client;};
    string get_ApiKey() const {return ApiKey;};
    void set_AvapiUrl(string AvapiUrl){this->AvapiUrl = AvapiUrl;};
    void set_Client(RestClient *Client){this->Client = Client;};
    void set_ApiKey(string ApiKey){this->ApiKey = ApiKey;};

    AvapiResponse_STOCH Query(string symbol
        ,Const_STOCH_interval interval
        ,string fastkperiod
        ,string slowkperiod
        ,string slowdperiod
        ,Const_STOCH_slowkmatype slowkmatype
        ,Const_STOCH_slowdmatype slowdmatype
        );
        
    AvapiResponse_STOCH Query(string symbol
        ,string interval
        ,string fastkperiod
        ,string slowkperiod
        ,string slowdperiod
        ,string slowkmatype
        ,string slowdmatype
        );
};

}//end namespace Avapi

#endif // STOCH_HPP_INCLUDED
