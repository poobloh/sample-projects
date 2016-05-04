/**
 *  Program 7
 *  WeatherService driver, tests methods with cached .json file and prints/analyzes data in table format
 *  CS108-2
 *  December 1 2015
 *  @author  Brandon Castro
 */

import java.util.ArrayList;

import realtimeweb.weatherservice.WeatherService;
import realtimeweb.weatherservice.domain.Report;
import realtimeweb.weatherservice.domain.Forecast;

public class WeatherWatcher {
    public static void main(String[] args) {
        System.out.println("Program 7, Brandon Castro, masc1733 ");

        WeatherService wthr = new WeatherService("cache.json");
        Report rep = wthr.getReport("blacksburg,va");
        ArrayList<Forecast> list = rep.getForecasts();

        System.out.println("Getting forecast for " + rep.getLocation().getName() + "... \n");
        int count=0, temps=0, highT=0, lowT=99, highP=0, lowP=99, rain=0, precip=0;
        System.out.println("+-----------------------+--------+------------------------+------+\n" +
                "|TIME PERIOD            | TEMPS. |            DESCRIPTION |PRECIP|\n" +
                "+-----------------------+--------+------------------------+------+");
        for (Forecast cast : list) {
            count++;
            System.out.printf("|%-23s", cast.getPeriodName()); // Friday Night
            System.out.printf("|   %-5s", cast.getTemperature()+" "); // 78
            System.out.printf("|%24s", cast.getDescription()); // "Sunny"
            System.out.printf("|%8s", cast.getProbabilityOfPrecipitation()+"%|\n");

            if(cast.getDescription().contains("Showers") || cast.getDescription().contains("Rain")
                    || cast.getDescription().contains("Thunderstorm"))
                rain++;
            if(cast.getTemperature() > highT)
                highT = cast.getTemperature();
            else if(cast.getTemperature() < lowT)
                lowT = cast.getTemperature();
            if(cast.getProbabilityOfPrecipitation() > highP)
                highP = cast.getProbabilityOfPrecipitation();
            else if(cast.getProbabilityOfPrecipitation() < lowP)
                lowP = cast.getProbabilityOfPrecipitation();
            temps += cast.getTemperature();
            precip += cast.getProbabilityOfPrecipitation();
        }

        System.out.println("+-----------------------+--------+-------------------------------+\n" +
                "|                    FORECAST ANALYSIS                           |\n" +
                "+----------------------------+-----------------------------------+");
        System.out.printf("|%-28s", "Number of RAINY days: ");
        System.out.printf("| %35s", rain+" |");
        System.out.printf("\n|%-28s", "Highest TEMP: ");
        System.out.printf("| %35s", highT+" |");
        System.out.printf("\n|%-28s", "Lowest TEMP: ");
        System.out.printf("| %35s", lowT+" |");
        System.out.printf("\n|%-28s", "Highest PRECIP: ");
        System.out.printf("| %35s", highP+"% |");
        System.out.printf("\n|%-28s", "Lowest PRECIP: ");
        System.out.printf("| %35s", lowP+"% |");
        System.out.printf("\n|%-28s", "Average TEMP: ");
        System.out.printf("| %35s", temps/count + " |");
        System.out.printf("\n|%-28s", "Average PROB OF PRECIP: ");
        System.out.printf("| %35s", precip / count + "% |");
        System.out.println("\n+----------------------------+-----------------------------------+");
    }
}
