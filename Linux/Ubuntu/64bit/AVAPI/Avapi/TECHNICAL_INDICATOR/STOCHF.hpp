#ifndef STOCHF_HPP_INCLUDED
#define STOCHF_HPP_INCLUDED

#include <string>
#include <map>
#include <list>
#include "../jsmn/jsmn.h"

using namespace std;

namespace Avapi {

class RestClient; //forward declaration

enum class Const_STOCHF_interval{
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

enum class Const_STOCHF_fastdmatype{
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

class MAP_STOCHF
{
public:
    static const map<Const_STOCHF_interval, string> s_interval_translation;
    static const map<Const_STOCHF_fastdmatype, string> s_fastdmatype_translation;
};

class MetaData_Type_STOCHF
{
private:
    string Symbol;
    string Indicator;
    string LastRefreshed;
    string Interval;
    string FastKPeriod;
    string FastDPeriod;
    string FastDMAType;
    string TimeZone;

public:
    MetaData_Type_STOCHF();
    MetaData_Type_STOCHF(const MetaData_Type_STOCHF& other); // copy constructor
    
    string get_Symbol() const {return Symbol;};
    string get_Indicator() const {return Indicator;};
    string get_LastRefreshed() const {return LastRefreshed;};
    string get_Interval() const {return Interval;};
    string get_FastKPeriod() const {return FastKPeriod;};
    string get_FastDPeriod() const {return FastDPeriod;};
    string get_FastDMAType() const {return FastDMAType;};
    string get_TimeZone() const {return TimeZone;};
    void set_Symbol(string Symbol){this->Symbol = Symbol;};
    void set_Indicator(string Indicator){this->Indicator = Indicator;};
    void set_LastRefreshed(string LastRefreshed){this->LastRefreshed = LastRefreshed;};
    void set_Interval(string Interval){this->Interval = Interval;};
    void set_FastKPeriod(string FastKPeriod){this->FastKPeriod = FastKPeriod;};
    void set_FastDPeriod(string FastDPeriod){this->FastDPeriod = FastDPeriod;};
    void set_FastDMAType(string FastDMAType){this->FastDMAType = FastDMAType;};
    void set_TimeZone(string TimeZone){this->TimeZone = TimeZone;};

    int ParseInternal(string& str_data, jsmntok_t* array_token ,int index, int token_size);
};

class TechnicalIndicator_Type_STOCHF
{
private:
    string FastK;
    string FastD;
    string DateTime;

public:
    TechnicalIndicator_Type_STOCHF();
    TechnicalIndicator_Type_STOCHF(const TechnicalIndicator_Type_STOCHF& other); // copy constructor

    string get_FastK() const {return FastK;};
    string get_FastD() const {return FastD;};
    string get_DateTime() const {return DateTime;};
    void set_FastK(string FastK){this->FastK = FastK;};
    void set_FastD(string FastD){this->FastD = FastD;};
    void set_DateTime(string DateTime){this->DateTime = DateTime;};

   int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class AvapiResponse_STOCHF_Content
{
private:
    MetaData_Type_STOCHF MetaData;
    list<TechnicalIndicator_Type_STOCHF> TechnicalIndicator;
    string str_prefix;
    bool error_status;
    string ErrorMessage;

public:
    AvapiResponse_STOCHF_Content();
    ~AvapiResponse_STOCHF_Content() {};
    AvapiResponse_STOCHF_Content(const AvapiResponse_STOCHF_Content& other); // copy constructor
    MetaData_Type_STOCHF& get_MetaData() {return MetaData;};
    list<TechnicalIndicator_Type_STOCHF>& get_TechnicalIndicator() {return TechnicalIndicator;};
    void set_Error(bool error_status) {this->error_status = error_status;};
    bool isError() {return error_status;};
    string get_ErrorMessage() {return ErrorMessage;};
    void set_ErrorMessage(string ErrorMessage) {this->ErrorMessage = str_prefix + ErrorMessage;};
};

class AvapiResponse_STOCHF
{
private:
    string LastHttpRequest;
    string RawData;
    AvapiResponse_STOCHF_Content* Data;

public:
    AvapiResponse_STOCHF();
    AvapiResponse_STOCHF(const AvapiResponse_STOCHF& other); // copy constructor
    AvapiResponse_STOCHF(AvapiResponse_STOCHF&& other); // move constructor
    AvapiResponse_STOCHF& operator=(const AvapiResponse_STOCHF& other); //copy assignment
    AvapiResponse_STOCHF& operator=(AvapiResponse_STOCHF&& other); //move assignment
    ~AvapiResponse_STOCHF();

    AvapiResponse_STOCHF_Content& get_Data() const {return *Data;};
    string get_LastHttpRequest() const {return LastHttpRequest;};
    string get_RawData() const {return RawData;};
    void set_LastHttpRequest(string LastHttpRequest){this->LastHttpRequest = LastHttpRequest;};
    void set_RawData(string RawData){this->RawData = RawData;};
};

class Impl_STOCHF
{
private:
    string AvapiUrl;
    string ApiKey;
    RestClient *Client;
    static string s_function;
    static Impl_STOCHF *s_instance;
    Impl_STOCHF() {};
    static const unsigned int START_TOKEN_SIZE = 3000;
    static void ParseInternal(AvapiResponse_STOCHF& Response);

public:
    static Impl_STOCHF& getInstance();
    static void destroyInstance();

    string get_AvapiUrl() const {return AvapiUrl;};
    RestClient* get_Client() const {return Client;};
    string get_ApiKey() const {return ApiKey;};
    void set_AvapiUrl(string AvapiUrl){this->AvapiUrl = AvapiUrl;};
    void set_Client(RestClient *Client){this->Client = Client;};
    void set_ApiKey(string ApiKey){this->ApiKey = ApiKey;};

    AvapiResponse_STOCHF Query(string symbol
        ,Const_STOCHF_interval interval
        ,string fastkperiod
        ,string fastdperiod
        ,Const_STOCHF_fastdmatype fastdmatype
        );
        
    AvapiResponse_STOCHF Query(string symbol
        ,string interval
        ,string fastkperiod
        ,string fastdperiod
        ,string fastdmatype
        );
};

}//end namespace Avapi

#endif // STOCHF_HPP_INCLUDED
