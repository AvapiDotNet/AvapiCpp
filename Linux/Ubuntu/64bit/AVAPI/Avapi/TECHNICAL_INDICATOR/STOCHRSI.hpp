#ifndef STOCHRSI_HPP_INCLUDED
#define STOCHRSI_HPP_INCLUDED

#include <string>
#include <map>
#include <list>
#include "../jsmn/jsmn.h"

using namespace std;

namespace Avapi {

class RestClient; //forward declaration

enum class Const_STOCHRSI_interval{
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

enum class Const_STOCHRSI_series_type{
    none,
    close,
    open,
    high,
    low,
};

enum class Const_STOCHRSI_fastdmatype{
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

class MAP_STOCHRSI
{
public:
    static const map<Const_STOCHRSI_interval, string> s_interval_translation;
    static const map<Const_STOCHRSI_series_type, string> s_series_type_translation;
    static const map<Const_STOCHRSI_fastdmatype, string> s_fastdmatype_translation;
};

class MetaData_Type_STOCHRSI
{
private:
    string Symbol;
    string Indicator;
    string LastRefreshed;
    string Interval;
    string TimePeriod;
    string FastKPeriod;
    string FastDPeriod;
    string FastDMAType;
    string SeriesType;
    string TimeZone;

public:
    MetaData_Type_STOCHRSI();
    MetaData_Type_STOCHRSI(const MetaData_Type_STOCHRSI& other); // copy constructor
    
    string get_Symbol() const {return Symbol;};
    string get_Indicator() const {return Indicator;};
    string get_LastRefreshed() const {return LastRefreshed;};
    string get_Interval() const {return Interval;};
    string get_TimePeriod() const {return TimePeriod;};
    string get_FastKPeriod() const {return FastKPeriod;};
    string get_FastDPeriod() const {return FastDPeriod;};
    string get_FastDMAType() const {return FastDMAType;};
    string get_SeriesType() const {return SeriesType;};
    string get_TimeZone() const {return TimeZone;};
    void set_Symbol(string Symbol){this->Symbol = Symbol;};
    void set_Indicator(string Indicator){this->Indicator = Indicator;};
    void set_LastRefreshed(string LastRefreshed){this->LastRefreshed = LastRefreshed;};
    void set_Interval(string Interval){this->Interval = Interval;};
    void set_TimePeriod(string TimePeriod){this->TimePeriod = TimePeriod;};
    void set_FastKPeriod(string FastKPeriod){this->FastKPeriod = FastKPeriod;};
    void set_FastDPeriod(string FastDPeriod){this->FastDPeriod = FastDPeriod;};
    void set_FastDMAType(string FastDMAType){this->FastDMAType = FastDMAType;};
    void set_SeriesType(string SeriesType){this->SeriesType = SeriesType;};
    void set_TimeZone(string TimeZone){this->TimeZone = TimeZone;};

    int ParseInternal(string& str_data, jsmntok_t* array_token ,int index, int token_size);
};

class TechnicalIndicator_Type_STOCHRSI
{
private:
    string FastK;
    string FastD;
    string DateTime;

public:
    TechnicalIndicator_Type_STOCHRSI();
    TechnicalIndicator_Type_STOCHRSI(const TechnicalIndicator_Type_STOCHRSI& other); // copy constructor

    string get_FastK() const {return FastK;};
    string get_FastD() const {return FastD;};
    string get_DateTime() const {return DateTime;};
    void set_FastK(string FastK){this->FastK = FastK;};
    void set_FastD(string FastD){this->FastD = FastD;};
    void set_DateTime(string DateTime){this->DateTime = DateTime;};

   int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class AvapiResponse_STOCHRSI_Content
{
private:
    MetaData_Type_STOCHRSI MetaData;
    list<TechnicalIndicator_Type_STOCHRSI> TechnicalIndicator;
    string str_prefix;
    bool error_status;
    string ErrorMessage;

public:
    AvapiResponse_STOCHRSI_Content();
    ~AvapiResponse_STOCHRSI_Content() {};
    AvapiResponse_STOCHRSI_Content(const AvapiResponse_STOCHRSI_Content& other); // copy constructor
    MetaData_Type_STOCHRSI& get_MetaData() {return MetaData;};
    list<TechnicalIndicator_Type_STOCHRSI>& get_TechnicalIndicator() {return TechnicalIndicator;};
    void set_Error(bool error_status) {this->error_status = error_status;};
    bool isError() {return error_status;};
    string get_ErrorMessage() {return ErrorMessage;};
    void set_ErrorMessage(string ErrorMessage) {this->ErrorMessage = str_prefix + ErrorMessage;};
};

class AvapiResponse_STOCHRSI
{
private:
    string LastHttpRequest;
    string RawData;
    AvapiResponse_STOCHRSI_Content* Data;

public:
    AvapiResponse_STOCHRSI();
    AvapiResponse_STOCHRSI(const AvapiResponse_STOCHRSI& other); // copy constructor
    AvapiResponse_STOCHRSI(AvapiResponse_STOCHRSI&& other); // move constructor
    AvapiResponse_STOCHRSI& operator=(const AvapiResponse_STOCHRSI& other); //copy assignment
    AvapiResponse_STOCHRSI& operator=(AvapiResponse_STOCHRSI&& other); //move assignment
    ~AvapiResponse_STOCHRSI();

    AvapiResponse_STOCHRSI_Content& get_Data() const {return *Data;};
    string get_LastHttpRequest() const {return LastHttpRequest;};
    string get_RawData() const {return RawData;};
    void set_LastHttpRequest(string LastHttpRequest){this->LastHttpRequest = LastHttpRequest;};
    void set_RawData(string RawData){this->RawData = RawData;};
};

class Impl_STOCHRSI
{
private:
    string AvapiUrl;
    string ApiKey;
    RestClient *Client;
    static string s_function;
    static Impl_STOCHRSI *s_instance;
    Impl_STOCHRSI() {};
    static const unsigned int START_TOKEN_SIZE = 3000;
    static void ParseInternal(AvapiResponse_STOCHRSI& Response);

public:
    static Impl_STOCHRSI& getInstance();
    static void destroyInstance();

    string get_AvapiUrl() const {return AvapiUrl;};
    RestClient* get_Client() const {return Client;};
    string get_ApiKey() const {return ApiKey;};
    void set_AvapiUrl(string AvapiUrl){this->AvapiUrl = AvapiUrl;};
    void set_Client(RestClient *Client){this->Client = Client;};
    void set_ApiKey(string ApiKey){this->ApiKey = ApiKey;};

    AvapiResponse_STOCHRSI Query(string symbol
        ,Const_STOCHRSI_interval interval
        ,string time_period
        ,Const_STOCHRSI_series_type series_type
        ,string fastkperiod
        ,string fastdperiod
        ,Const_STOCHRSI_fastdmatype fastdmatype
        );
        
    AvapiResponse_STOCHRSI Query(string symbol
        ,string interval
        ,string time_period
        ,string series_type
        ,string fastkperiod
        ,string fastdperiod
        ,string fastdmatype
        );
};

}//end namespace Avapi

#endif // STOCHRSI_HPP_INCLUDED
