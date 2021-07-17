//
// Created by lullibeps on 14/07/21.
//

#ifndef CLOCKTIMER_CLOCKDATA_H
#define CLOCKTIMER_CLOCKDATA_H

enum class FormatoData {
    europeo, cinese, statunitense
};//gma, amg, mga
enum class FormatoOrario {
    h12, h24
};

class ClockData {
private:
    FormatoData formatoData;
    FormatoOrario formatoOrario;
    struct tm customData{};
    bool useCustomData;
    double customDataDiff;
public:
    ClockData(FormatoData formatoData = FormatoData::europeo, FormatoOrario formatoOrario = FormatoOrario::h24);

    std::string getClockData();

    void setFormatoData(FormatoData formatData);

    void setFormatoOrario(FormatoOrario formatOrario);

    FormatoData getFormatoData() const;

    FormatoOrario getFormatoOrario() const;

    void setUseCustomData(bool customDateSet);

    void setCustomData(int day, int mon, int year, int hour, int min, int sec);

    bool isUseCustomData() const;
};

#endif //CLOCKTIMER_CLOCKDATA_H
