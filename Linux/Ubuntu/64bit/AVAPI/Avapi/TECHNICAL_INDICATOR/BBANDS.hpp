#ifndef BBANDS_HPP_INCLUDED
#define BBANDS_HPP_INCLUDED

#include <string>
#include <map>
#include <list>
#include "../jsmn/jsmn.h"

using namespace std;

namespace Avapi {

class RestClient; //forward declaration

enum class Const_BBANDS_interval{
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

enum class Const_BBANDS_series_type{
    none,
    close,
    open,
    high,
    low,
};

enum class Const_BBANDS_matype{
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

class MAP_BBANDS
{
public:
    static const map<Const_BBANDS_interval, string> s_interval_translation;
    static const map<Const_BBANDS_series_type, string> s_series_type_translation;
    static const map<Const_BBANDS_matype, string> s_matype_translation;
};

class MetaData_Type_BBANDS
{
private:
    string Symbol;
    string Indicator;
    string LastRefreshed;
    string Interval;
    string TimePeriod;
    string DeviationUpper;
    string DeviationLower;
    string MAType;
    string SeriesType;
    string TimeZone;

public:
    MetaData_Type_BBANDS();
    MetaData_Type_BBANDS(const MetaData_Type_BBANDS& other); // copy constructor
    
    string get_Symbol() const {return Symbol;};
    string get_Indicator() const {return Indicator;};
    string get_LastRefreshed() const {return LastRefreshed;};
    string get_Interval() const {return Interval;};
    string get_TimePeriod() const {return TimePeriod;};
    string get_DeviationUpper() const {return DeviationUpper;};
    string get_DeviationLower() const {return DeviationLower;};
    string get_MAType() const {return MAType;};
    string get_SeriesType() const {return SeriesType;};
    string get_TimeZone() const {return TimeZone;};
    void set_Symbol(string Symbol){this->Symbol = Symbol;};
    void set_Indicator(string Indicator){this->Indicator = Indicator;};
    void set_LastRefreshed(string LastRefreshed){this->LastRefreshed = LastRefreshed;};
    void set_Interval(string Interval){this->Interval = Interval;};
    void set_TimePeriod(string TimePeriod){this->TimePeriod = TimePeriod;};
    void set_DeviationUpper(string DeviationUpper){this->DeviationUpper = DeviationUpper;};
    void set_DeviationLower(string DeviationLower){this->DeviationLower = DeviationLower;};
    void set_MAType(string MAType){this->MAType = MAType;};
    void set_SeriesType(string SeriesType){this->SeriesType = SeriesType;};
    void set_TimeZone(string TimeZone){this->TimeZone = TimeZone;};

    int ParseInternal(string& str_data, jsmntok_t* array_token ,int index, int token_size);
};

class TechnicalIndicator_Type_BBANDS
{
private:
    string RealLowerBand;
    string RealUpperBand;
    string RealMiddleBand;
    string DateTime;

public:
    TechnicalIndicator_Type_BBANDS();
    TechnicalIndicator_Type_BBANDS(const TechnicalIndicator_Type_BBANDS& other); // copy constructor

    string get_RealLowerBand() const {return RealLowerBand;};
    string get_RealUpperBand() const {return RealUpperBand;};
    string get_RealMiddleBand() const {return RealMiddleBand;};
    string get_DateTime() const {return DateTime;};
    void set_RealLowerBand(string RealLowerBand){this->RealLowerBand = RealLowerBand;};
    void set_RealUpperBand(string RealUpperBand){this->RealUpperBand = RealUpperBand;};
    void set_RealMiddleBand(string RealMiddleBand){this->RealMiddleBand = RealMiddleBand;};
    void set_DateTime(string DateTime){this->DateTime = DateTime;};

   int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class AvapiResponse_BBANDS_Content
{
private:
    MetaData_Type_BBANDS MetaData;
    list<TechnicalIndicator_Type_BBANDS> TechnicalIndicator;
    string str_prefix;
    bool error_status;
    string ErrorMessage;

public:
    AvapiResponse_BBANDS_Content();
    ~AvapiResponse_BBANDS_Content() {};
    AvapiResponse_BBANDS_Content(const AvapiResponse_BBANDS_Content& other); // copy constructor
    MetaData_Type_BBANDS& get_MetaData() {return MetaData;};
    list<TechnicalIndicator_Type_BBANDS>& get_TechnicalIndicator() {return TechnicalIndicator;};
    void set_Error(bool error_status) {this->error_status = error_status;};
    bool isError() {return error_status;};
    string get_ErrorMessage() {return ErrorMessage;};
    void set_ErrorMessage(string ErrorMessage) {this->ErrorMessage = str_prefix + ErrorMessage;};
};

class AvapiResponse_BBANDS
{
private:
    string LastHttpRequest;
    string RawData;
    AvapiResponse_BBANDS_Content* Data;

public:
    AvapiResponse_BBANDS();
    AvapiResponse_BBANDS(const AvapiResponse_BBANDS& other); // copy constructor
    AvapiResponse_BBANDS(AvapiResponse_BBANDS&& other); // move constructor
    AvapiResponse_BBANDS& operator=(const AvapiResponse_BBANDS& other); //copy assignment
    AvapiResponse_BBANDS& operator=(AvapiResponse_BBANDS&& other); //move assignment
    ~AvapiResponse_BBANDS();

    AvapiResponse_BBANDS_Content& get_Data() const {return *Data;};
    string get_LastHttpRequest() const {return LastHttpRequest;};
    string get_RawData() const {return RawData;};
    void set_LastHttpRequest(string LastHttpRequest){this->LastHttpRequest = LastHttpRequest;};
    void set_RawData(string RawData){this->RawData = RawData;};
};

class Impl_BBANDS
{
private:
    string AvapiUrl;
    string ApiKey;
    RestClient *Client;
    static string s_function;
    static Impl_BBANDS *s_instance;
    Impl_BBANDS() {};
    static const unsigned int START_TOKEN_SIZE = 3000;
    static void ParseInternal(AvapiResponse_BBANDS& Response);

public:
    static Impl_BBANDS& getInstance();
    static void destroyInstance();

    string get_AvapiUrl() const {return AvapiUrl;};
    RestClient* get_Client() const {return Client;};
    string get_ApiKey() const {return ApiKey;};
    void set_AvapiUrl(string AvapiUrl){this->AvapiUrl = AvapiUrl;};
    void set_Client(RestClient *Client){this->Client = Client;};
    void set_ApiKey(string ApiKey){this->ApiKey = ApiKey;};

    AvapiResponse_BBANDS Query(string symbol
        ,Const_BBANDS_interval interval
        ,string time_period
        ,Const_BBANDS_series_type series_type
        ,string nbdevup
        ,string nbdevdn
        ,Const_BBANDS_matype matype
        );
        
    AvapiResponse_BBANDS Query(string symbol
        ,string interval
        ,string time_period
        ,string series_type
        ,string nbdevup
        ,string nbdevdn
        ,string matype
        );
};

}//end namespace Avapi

#endif // BBANDS_HPP_INCLUDED
