#include "stats.h"

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
        std::cout<<__func__<<" min:"<<StatisticsOfNumbers.min<<" max:"<<StatisticsOfNumbers.max<<" average:"<<StatisticsOfNumbers.average<<std::endl;
    }
    
    return StatisticsOfNumbers;
}

bool EmailAlert::getEmailSentStatus()
{
    std::cout<<__func__<<" EmailSentStatus:"<<emailSent<<std::endl;
    return emailSent;
}

void EmailAlert::setEmailSentStatus(bool emailSentStatus)
{
    emailSent = emailSentStatus;
    std::cout<<__func__<<" EmailSentStatus:"<<emailSent<<std::endl;
}

bool LEDAlert::getLedGlowStatus()
{
    std::cout<<__func__<<" LedGlowStatus:"<<ledGlows<<std::endl;
    return ledGlows;
}

void LEDAlert::setLedGlowStatus(bool ledGlowStatus)
{
    ledGlows = ledGlowStatus;
    std::cout<<__func__<<" LedGlowStatus:"<<ledGlows<<std::endl;
}

void StatsAlerter::checkAndAlert(const std::vector<double>& values)
{
    double maximumValue = *max_element(values.begin(), values.end());
    std::cout<<__func__<<" maximumValue:"<<maximumValue<<" maximumThreshold:"<<maximumThreshold<<std::endl;
    if(maximumValue > maximumThreshold)
    {
        (alerter.at(EMAIL_ALERT))->setEmailSentStatus(true);
        (alerter.at(LED_ALERT))->setLedGlowStatus(true);
    }
}
