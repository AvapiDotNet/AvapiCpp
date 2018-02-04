#ifndef AVAPICONNECTION_HPP_INCLUDED
#define AVAPICONNECTION_HPP_INCLUDED
#include <string>
#include <iostream>
#include <mutex>

using namespace std;

namespace Avapi{

//forward declaration
class RestClient;
class Impl_TIME_SERIES_INTRADAY;
class Impl_TIME_SERIES_DAILY;
class Impl_TIME_SERIES_DAILY_ADJUSTED;
class Impl_TIME_SERIES_WEEKLY;
class Impl_TIME_SERIES_WEEKLY_ADJUSTED;
class Impl_TIME_SERIES_MONTHLY;
class Impl_TIME_SERIES_MONTHLY_ADJUSTED;
class Impl_SMA;
class Impl_EMA;
class Impl_WMA;
class Impl_DEMA;
class Impl_TEMA;
class Impl_TRIMA;
class Impl_KAMA;
class Impl_MAMA;
class Impl_T3;
class Impl_MACD;
class Impl_MACDEXT;
class Impl_STOCH;
class Impl_STOCHF;
class Impl_RSI;
class Impl_STOCHRSI;
class Impl_WILLR;
class Impl_ADX;
class Impl_ADXR;
class Impl_APO;
class Impl_PPO;
class Impl_MOM;
class Impl_BOP;
class Impl_CCI;
class Impl_CMO;
class Impl_ROC;
class Impl_ROCR;
class Impl_AROON;
class Impl_AROONOSC;
class Impl_MFI;
class Impl_TRIX;
class Impl_ULTOSC;
class Impl_DX;
class Impl_MINUS_DI;
class Impl_PLUS_DI;
class Impl_MINUS_DM;
class Impl_PLUS_DM;
class Impl_BBANDS;
class Impl_MIDPOINT;
class Impl_MIDPRICE;
class Impl_SAR;
class Impl_TRANGE;
class Impl_ATR;
class Impl_NATR;
class Impl_AD;
class Impl_ADOSC;
class Impl_OBV;
class Impl_HT_TRENDLINE;
class Impl_HT_SINE;
class Impl_HT_TRENDMODE;
class Impl_HT_DCPERIOD;
class Impl_HT_DCPHASE;
class Impl_HT_PHASOR;
class Impl_DIGITAL_CURRENCY_INTRADAY;
class Impl_DIGITAL_CURRENCY_DAILY;
class Impl_DIGITAL_CURRENCY_WEEKLY;
class Impl_DIGITAL_CURRENCY_MONTHLY;
class Impl_CURRENCY_EXCHANGE_RATE;
class Impl_SECTOR;
class Impl_BATCH_STOCK_QUOTES;

//class used to throw the execption related to AvapiConnection
class AvapiConnectionError
{
private:
    string error;

public:
    AvapiConnectionError(string error):error(error){;}
    string get_error(){return error;}
};

class AvapiConnection
{
private:
    string AvapiUrl;
    static const string AvapiUrlDefault;
    string ApiKey;
    RestClient* Client; // Rest client instance
    static mutex avapi_con_mutex;
    static AvapiConnection* s_instance;
    AvapiConnection():ApiKey(""), Client(nullptr) {};
    int init_AvapiConnection();
    void destroy_AvapiConnection();

public:
    static AvapiConnection* getInstance();
    static void destroyInstance();
    AvapiConnection(AvapiConnection const&)= delete;
    AvapiConnection& operator=(AvapiConnection const&)= delete;

    string get_AvapiUrl() const;
    string get_AvapiUrlDefault() const {return AvapiUrlDefault;};
    string get_ApiKey() const {return ApiKey;};
    void set_AvapiUrl(string AvapiUrl);
    void set_ApiKey(string ApiKey);
    
    //It is not Thread-safe
    Impl_TIME_SERIES_INTRADAY& GetQueryObject_TIME_SERIES_INTRADAY() const;
    Impl_TIME_SERIES_DAILY& GetQueryObject_TIME_SERIES_DAILY() const;
    Impl_TIME_SERIES_DAILY_ADJUSTED& GetQueryObject_TIME_SERIES_DAILY_ADJUSTED() const;
    Impl_TIME_SERIES_WEEKLY& GetQueryObject_TIME_SERIES_WEEKLY() const;
    Impl_TIME_SERIES_WEEKLY_ADJUSTED& GetQueryObject_TIME_SERIES_WEEKLY_ADJUSTED() const;
    Impl_TIME_SERIES_MONTHLY& GetQueryObject_TIME_SERIES_MONTHLY() const;
    Impl_TIME_SERIES_MONTHLY_ADJUSTED& GetQueryObject_TIME_SERIES_MONTHLY_ADJUSTED() const;
    Impl_SMA& GetQueryObject_SMA() const;
    Impl_EMA& GetQueryObject_EMA() const;
    Impl_WMA& GetQueryObject_WMA() const;
    Impl_DEMA& GetQueryObject_DEMA() const;
    Impl_TEMA& GetQueryObject_TEMA() const;
    Impl_TRIMA& GetQueryObject_TRIMA() const;
    Impl_KAMA& GetQueryObject_KAMA() const;
    Impl_MAMA& GetQueryObject_MAMA() const;
    Impl_T3& GetQueryObject_T3() const;
    Impl_MACD& GetQueryObject_MACD() const;
    Impl_MACDEXT& GetQueryObject_MACDEXT() const;
    Impl_STOCH& GetQueryObject_STOCH() const;
    Impl_STOCHF& GetQueryObject_STOCHF() const;
    Impl_RSI& GetQueryObject_RSI() const;
    Impl_STOCHRSI& GetQueryObject_STOCHRSI() const;
    Impl_WILLR& GetQueryObject_WILLR() const;
    Impl_ADX& GetQueryObject_ADX() const;
    Impl_ADXR& GetQueryObject_ADXR() const;
    Impl_APO& GetQueryObject_APO() const;
    Impl_PPO& GetQueryObject_PPO() const;
    Impl_MOM& GetQueryObject_MOM() const;
    Impl_BOP& GetQueryObject_BOP() const;
    Impl_CCI& GetQueryObject_CCI() const;
    Impl_CMO& GetQueryObject_CMO() const;
    Impl_ROC& GetQueryObject_ROC() const;
    Impl_ROCR& GetQueryObject_ROCR() const;
    Impl_AROON& GetQueryObject_AROON() const;
    Impl_AROONOSC& GetQueryObject_AROONOSC() const;
    Impl_MFI& GetQueryObject_MFI() const;
    Impl_TRIX& GetQueryObject_TRIX() const;
    Impl_ULTOSC& GetQueryObject_ULTOSC() const;
    Impl_DX& GetQueryObject_DX() const;
    Impl_MINUS_DI& GetQueryObject_MINUS_DI() const;
    Impl_PLUS_DI& GetQueryObject_PLUS_DI() const;
    Impl_MINUS_DM& GetQueryObject_MINUS_DM() const;
    Impl_PLUS_DM& GetQueryObject_PLUS_DM() const;
    Impl_BBANDS& GetQueryObject_BBANDS() const;
    Impl_MIDPOINT& GetQueryObject_MIDPOINT() const;
    Impl_MIDPRICE& GetQueryObject_MIDPRICE() const;
    Impl_SAR& GetQueryObject_SAR() const;
    Impl_TRANGE& GetQueryObject_TRANGE() const;
    Impl_ATR& GetQueryObject_ATR() const;
    Impl_NATR& GetQueryObject_NATR() const;
    Impl_AD& GetQueryObject_AD() const;
    Impl_ADOSC& GetQueryObject_ADOSC() const;
    Impl_OBV& GetQueryObject_OBV() const;
    Impl_HT_TRENDLINE& GetQueryObject_HT_TRENDLINE() const;
    Impl_HT_SINE& GetQueryObject_HT_SINE() const;
    Impl_HT_TRENDMODE& GetQueryObject_HT_TRENDMODE() const;
    Impl_HT_DCPERIOD& GetQueryObject_HT_DCPERIOD() const;
    Impl_HT_DCPHASE& GetQueryObject_HT_DCPHASE() const;
    Impl_HT_PHASOR& GetQueryObject_HT_PHASOR() const;
    Impl_DIGITAL_CURRENCY_INTRADAY& GetQueryObject_DIGITAL_CURRENCY_INTRADAY() const;
    Impl_DIGITAL_CURRENCY_DAILY& GetQueryObject_DIGITAL_CURRENCY_DAILY() const;
    Impl_DIGITAL_CURRENCY_WEEKLY& GetQueryObject_DIGITAL_CURRENCY_WEEKLY() const;
    Impl_DIGITAL_CURRENCY_MONTHLY& GetQueryObject_DIGITAL_CURRENCY_MONTHLY() const;
    Impl_CURRENCY_EXCHANGE_RATE& GetQueryObject_CURRENCY_EXCHANGE_RATE() const;
    Impl_SECTOR& GetQueryObject_SECTOR() const;
    Impl_BATCH_STOCK_QUOTES& GetQueryObject_BATCH_STOCK_QUOTES() const;
};

}//end namespace Avapi

#endif // AVAPICONNECTION_HPP_INCLUDED
