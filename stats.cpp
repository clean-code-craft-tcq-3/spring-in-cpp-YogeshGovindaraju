#include "stats.h"

namespace std;

Stats Statistics::ComputeStatistics(const std::vector<double>& numbers)
{
    Stats StatisticsOfNumbers;
    
    if(numbers.empty())
    {
        StatisticsOfNumbers.min = NAN;
        StatisticsOfNumbers.max = NAN;
        StatisticsOfNumbers.average = NAN;
    }
    else
    {
        StatisticsOfNumbers.min = *min_element(numbers.begin(), numbers.end());
        StatisticsOfNumbers.max = *max_element(numbers.begin(), numbers.end());
        StatisticsOfNumbers.average = accumulate(numbers.begin(), numbers.end(), 0.0)/numbers.size();
        cout<<__func__<<" min:"<<StatisticsOfNumbers.min<<" max:"<<StatisticsOfNumbers.max<<" average:"<<StatisticsOfNumbers.average<<endl;
    }
    
    return StatisticsOfNumbers;
}

bool EmailAlert::getEmailSentStatus()
{
    cout<<__func__<<" EmailSentStatus:"<<emailSent<<endl;
    return emailSent;
}

void EmailAlert::setEmailSentStatus(bool emailSentStatus)
{
    emailSent = emailSentStatus;
    cout<<__func__<<" EmailSentStatus:"<<emailSent<<endl;
}

bool LEDAlert::getLedGlowStatus()
{
    cout<<__func__<<" LedGlowStatus:"<<ledGlows<<endl;
    return ledGlows;
}

void LEDAlert::setLedGlowStatus(bool ledGlowStatus)
{
    ledGlows = ledGlowStatus;
    cout<<__func__<<" LedGlowStatus:"<<ledGlows<<endl;
}

void StatsAlerter::checkAndAlert(const std::vector<double>& values)
{
    double maximumValue = *max_element(values.begin(), values.end());
    cout<<__func__<<" maximumValue:"<<maximumValue<<" maximumThreshold:"<<maximumThreshold<<endl;
    if(maximumValue > maximumThreshold)
    {
        alerterInstance = alerter.at(EMAIL_ALERT);
        alerterInstance->setEmailSentStatus(true);
        alerterInstance = alerter.at(LED_ALERT);
        alerterInstance->setLedGlowStatus(true);
    }
}
