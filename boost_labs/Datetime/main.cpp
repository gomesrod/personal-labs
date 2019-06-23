#include <iostream>

#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;

int main()
{
    boost::gregorian::date invalidDt(boost::date_time::not_a_date_time);
    cout << invalidDt << endl;

    try {
        boost::gregorian::date errorDate(2013, 15, 30);
    } catch (boost::gregorian::bad_month& e) {
        cerr << e.what() << endl;
    }

    boost::gregorian::date birthDate(1981, 04, 27);
    cout << birthDate << endl;
    cout << birthDate.day() << " / " << birthDate.month() << " / " << birthDate.year() << endl;

    boost::gregorian::date today =  boost::gregorian::day_clock::universal_day();
    cout << today << endl;
    cout << today.day() << " / " << today.month() << " / " << today.year() << endl;

    boost::gregorian::date_duration lifetime = today - birthDate;
    cout << "In days: " << lifetime.days() << "   In years: " << lifetime.days() / 365 << endl;

    return 0;
}
