#include <iostream>
#include <vector>
#include <time.h>
#include <random>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>


struct ExchangeRate
{
    std::string date;
    float rate;
};

std::vector<ExchangeRate> read_file(std::string filename, char separator = ','){
    std::fstream file(filename, std::ios::in);
    std::vector<ExchangeRate> exchange_rates;
    if (file.is_open()) {
        std::string line;
        while (getline(file,line)) {
            std::stringstream ss(line); // to parse line in getline
            ExchangeRate exchange_rate;
            std::string reading_string;
            getline(ss,reading_string,separator);
            exchange_rate.date = reading_string;
            getline(ss,reading_string,separator);
            exchange_rate.rate = std::stof(reading_string);
            exchange_rates.emplace_back(exchange_rate);
        }
        file.close();
    }
    return exchange_rates;
}
void print_vector2d(const std::vector<std::vector<int>>& array)
{
    for (int i = 0; i < array.size(); i++) {
        std::vector<int> row;
        for (int j = 0; j < array[0].size(); j++) {
            std::cout << array[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<int>> create_random_vector2d(const int& min,const int& max,const int& rows,const int& cols){
    std::vector<std::vector<int>> two_dimensional_vector;
    for (int i = 0; i < rows; i++) {
        std::vector<int> row;
        for (int j = 0; j < cols; j++) {
            row.emplace_back(min + rand()%(max-min+1));
        }
        two_dimensional_vector.emplace_back(row);
    }
    return two_dimensional_vector;
}

bool usd_pln_rate(const ExchangeRate& rate1,const ExchangeRate& rate2){
    return rate1.rate < rate2.rate;
}

bool year_2020(const ExchangeRate& rate){
    int year = std::stoi(rate.date.substr(0, rate.date.find('-')));
    return year >= 2020;
}

bool rate_over(const ExchangeRate& rate){
    return rate.rate > 4.22;
}

void assignment(){
    std::vector<ExchangeRate> exchange_rates = read_file("USDvsPLN.csv");
    std::vector<ExchangeRate>::const_iterator min_el =  std::min_element(exchange_rates.begin(),exchange_rates.end(),usd_pln_rate);
    std::vector<ExchangeRate>::const_iterator max_el =  std::max_element(exchange_rates.begin(),exchange_rates.end(),usd_pln_rate);

    //In above example you can use (*min_el).date instead of min_el->date.
    std::cout << "Smallest rate: " << min_el->date << " : " << min_el->rate << std::endl;
    std::cout << "Largest rate: " << max_el->date << " : " << max_el->rate << std::endl;


    std::cout << exchange_rates[0].date.substr(0, exchange_rates[0].date.find('-')) << std::endl;
    bool all_2020 = std::all_of(exchange_rates.begin(),exchange_rates.end(),year_2020);
    if(all_2020){
        std::cout << "All dates are from year 2020" << std::endl;
    }
    else{
        std::cout << "Not every date is from year 2020" << std::endl;
    }

    std::vector<ExchangeRate>::iterator rate_over_422 = std::find_if(exchange_rates.begin(),exchange_rates.end(),rate_over);
    std::cout << "Date when rate went over 4.22 first time: " << rate_over_422->date << std::endl;

    int rate_over_422_counts = std::count_if(exchange_rates.begin(),exchange_rates.end(),rate_over);
    std::cout << "There were " << rate_over_422_counts << " days when rate has been over 4.22" << std::endl;
}

int main()
{
    const int number_of_rows = 5;
    const int number_of_cols = 5;
    srand(time(nullptr));

    std::vector<std::vector<int>> two_dimensional_vector;

    for (int i = 0; i < number_of_rows; i++) {
        std::vector<int> row;
        for (int j = 0; j < number_of_cols; j++) {
            row.emplace_back(10 * i + j);
        }

        two_dimensional_vector.emplace_back(row);
    }

    //std::cout << "Row 2, column 3: " << two_dimensional_vector[2][3] << std::endl;
    print_vector2d(two_dimensional_vector);
    std::vector<std::vector<int>> rand_vector = create_random_vector2d(0,10,3,3);
    print_vector2d(rand_vector);
    assignment();
    return 0;
}
