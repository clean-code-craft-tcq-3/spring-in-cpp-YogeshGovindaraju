#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <bits/stdc++.h>

#define EMAIL_ALERT 0
#define LED_ALERT 1

struct Stats
{
    double min;
    double max;
    double average;
};

class IAlerter
{
    protected:
    bool emailSent;
    bool ledGlows;
    
    public:
    IAlerter()
    {
        emailSent = false;
        ledGlows = false;
    }
    virtual void setEmailSentStatus(bool emailSentStatus){};
    virtual void setLedGlowStatus(bool ledGlowStatus){};
};

class EmailAlert: public IAlerter
{
    public:
    bool getEmailSentStatus();
    void setEmailSentStatus(bool emailSentStatus);
};

class LEDAlert: public IAlerter
{
    public:
    bool getLedGlowStatus();
    void setLedGlowStatus(bool ledGlowStatus);
};

class StatsAlerter
{
    private:
    float maximumThreshold;
    IAlerter *alerterInstance;
    std::vector<IAlerter*> alerter;
    
    public:
    StatsAlerter(const float maxThreshold, std::vector<IAlerter*> alerters)
    {
        maximumThreshold = maxThreshold;
        alerter = alerters;
    }
    ~StatsAlerter()
    {
        delete alerterInstance;
    }
    void checkAndAlert(const std::vector<double>& values);
};

namespace Statistics
{
    Stats ComputeStatistics(const std::vector<double>& );
}
