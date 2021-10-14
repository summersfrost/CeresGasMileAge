/*CERES GAS MILEAGE
Submitted by: Benjie  S. Juabot
Submitted to: Engr, Victor John L. Anunciado
In completion of Midterm Projects

Logic and Concepts Used:
So the goal bere is to calculate the miles/gallons here and proceed to the calculation of the average tank of all busses
and its savings and excess of gasolines and amounts and its total savings or loss. Kilometers and Liters is use because it is commonly use
I rarely hear of gallons use in gasolines so inorder to meet the correct given miles/gallon Km is converted to miles as well as the liters to gallons

So loops are used here and switch statements and my forbidden formula in order to calculate it right*
So basically the loops are for the adding of busses and if the user wants to stop the adding of busses it will terminate the loop and proceed
to the calculation of all values.

So the most crucial problem I have here is the formulas in order to comeup the correct output. and Many variables are used but it is needed since
two measurements are used and each variable has its own purpose and without them the program will not do its job. */



#include <stdio.h>
#include <stdlib.h>

int main()
{
    //DECLARATIONS OF VARIABLES
    float gasoline_week; //Given Estimated gasoline to be used for a week
    float gasoline_day; // Gasoline Used in a day
    float travel_week_km; //total distance travel in a week
    float travel_week_miles; // travel week km converted into miles
    int days=7; //we can have this for a month or let the user input the number of days but the problem specified 1 week so its inputted
    int bus; //Number of bus that is computed
    int no_bus; //Just the loop for the bus
    float price; //Price of the gasoline
    float gallons; //liters of gasoline week converted into gallons
    float total; //price of the overall gasoline in a week
    float km_day; //distance travelled in km
    float estimated_day_km;//the kilometers/liters in a day
    float estimated_day_miles; //km/l is converted into Miles/Galoons in a day
    float gasoline_used_gallons;//gasoline used in a week in gallons
    float gasoline_used_liters; // gasoline used in a week in liters
    float weekly_deficit; //weekly deficit of each bus this happens when the bus exceeds the estimate amount of gasoline given this is for money
    float weekly_savings; // weekly savings of a bus where he consumes less gasoline given also this is for money
    float liters_saved_week; //liters of gasolines saved
    float gallons_saved_week;//converted liters of gasoline save
    float liters_deficit_week; // excess usage of gasoline in liters
    float gallons_deficit_week; // converted liter deficit
    float total_deficit=0;// overall deficit. value is 0 because no computation happens
    float total_savings=0;// overall savings. value is 0 because no computation happens
    float total_gasoline_savings_liters=0; //overall gasoline saved in liters
    float total_gasoline_savings_gallons; //overall gasoline in gallons just convert the liter
    float total_gasoline_deficit_liters=0; //overall excess usage of gasoline
    float total_gasoline_deficit_gallons;//excess converted into gallons
    int validation;//this is for the loop where if bus will be added more
    int choices;//this is for the validation loop pertaining to yes or no
    float average_km; //average kilometer/Liters of the buses
    float average_miles; // Convert the kilometer/liter into Miles/Galloon
    float gain_loss; // pertains how much the company saved or loss
    float total_ave_km;//summation of the kilometer/liter

//***************************************************************************************************************************************//
    printf("CERES BUS LINE GAS MILEAGE\n"); //just the title
      printf("**********************************************************************************************************************\n");

    //THIS IS FOR THE ESTIMATED COST OF MATERIALS USED FOR WEEK one setup only no loops
    printf("Estimated Liters of Gasoline used for each bus used for a week: "); scanf("%5f",&gasoline_week); //gasoline given by the company
    printf("Current Price of Gasoline: Php "); scanf("%5f",&price); //price of the gasoline per liter
    printf("\nCOST ESTIMATES:\n ");

    gallons=gasoline_week/3.785; //convert the gas that will be used for a week into gallons because it is given as liters.
    total=gasoline_week*price; //overall price of the gasoline

    printf("%.2f Liters or %.2f gallons of Gasoline used in a week which cost PHP %.2f per liter: PHP %.2f  \n ",gasoline_week,gallons,price,total);
    printf("**********************************************************************************************************************\n");

//*************************************************************************************************************************************************//

    //Main Program starts executing and inputs cost estimates for aday
    printf("Computations: \n\n");

    //Loop for number of buses and computation of usage and cost per bus
        for(no_bus=1, bus=1;no_bus>0;bus++){
        //INPUT OF HOW MANY KM'S TRAVELLED AND GASOLINE USED PER DAY
        printf("Liters of Gasolines used by the Bus %d for a day:",bus); scanf("%5f",&gasoline_day);
        printf("Kilometers driven:"); scanf("%5f",&km_day);

//***********************************************************************************************************************************************************

        //Results of the computations
        printf("\nRESULTS:\n\n");
        //This is the cost for a day
        printf("Daily Cost:\n");
        estimated_day_km=km_day/gasoline_day; //kilometers/Liters
        estimated_day_miles=(km_day/1.609)/(gasoline_day/3.785); // kilometers/liters converted into miles/gallons

        printf("Kilometers/Liter for bus %d tank  was: %.2f\n",bus,estimated_day_km);
        printf("Miles/Gallons for bus %d tank was: %.2f\n\n",bus,estimated_day_miles);

//*****************************************************************************************************************//

         //weekly cost

       printf("Weekly Cost:\n");

       //Calculations
        gasoline_used_liters=gasoline_day*days; //multiply the cost of bus perday into 7 which is number of days for a week
        gasoline_used_gallons=gasoline_used_liters/3.785; //liters into gallons this will be the amount of gas use in a week
        travel_week_km=km_day*days; //this willl be the total distance traveled in a week
        travel_week_miles=travel_week_km/1.609; //convert the kilometers into miles

        printf("Bus %d consumes %.2f Liters or %.2f gallons of gasoline for a week.\n",bus,gasoline_used_liters,gasoline_used_gallons);
        printf("Bus %d travel a distance of %.2f kilometers or %.2f miles for a week\n\n",bus,travel_week_km,travel_week_miles);
//****************************************************************************************************************//
        //CHECKING IF THE BUS HAS SAVED OR EXCEED THE ESTIMATED COST OF MATERIALS

        printf("Savings or Deficit:\n");
            if(gasoline_used_liters<=gasoline_week){ //this will run if the gasoline being used is less that the given amount this is for savings

            liters_saved_week=gasoline_week-gasoline_used_liters; //computes the liters saved by subtracting the given
            gallons_saved_week=liters_saved_week/3.875; //convert into gallons
            weekly_savings=liters_saved_week*price; // the money saved from the gasoline that is saved

            printf("Bus %d saved %.2f liters or %.2f gallons of gasoline which cost PHP %.2f \n",bus,liters_saved_week,gallons_saved_week,weekly_savings);
              printf("**********************************************************************************************************************\n");
               }
        else{ //directly runs if it exceed, in short words this is for deficits

            liters_deficit_week=gasoline_used_liters-gasoline_week; //getting the excess same formula but this will be separated since this is loss
            gallons_deficit_week=liters_deficit_week/3.875; //convert into gallons
            weekly_deficit=liters_deficit_week*price; //amount of liters multiply by the price to get the loss

            printf("Bus %d deficit %.2f Liters or %.2f Gallons of Gasoline amounting PHP %.2f this week.\n",bus,liters_deficit_week,
                   gallons_deficit_week,weekly_deficit);
            printf("**********************************************************************************************************************\n");

        }

//*********************************************************************************************************************************************//

         //Computation of overall
         // this will assign the summation of all values needed for the average and overall saving or loss
         //this is printed here since the process of getting every calculation is done, once the loop happens it will add the previous value into new
        total_ave_km+=estimated_day_km; //summation of all kilometer/liter
        total_gasoline_savings_liters+=liters_saved_week; //total gasoline saved for all the buses
        total_gasoline_savings_gallons=total_gasoline_savings_liters/3.875; //savings of gas converted into gallons
        total_gasoline_deficit_liters+=liters_deficit_week; //summation of excess gasoline
        total_gasoline_deficit_gallons=total_gasoline_deficit_liters/3.875; //excess of gas converted into gallons
        total_savings+=weekly_savings; //summation of all savings, for money
        total_deficit+=weekly_deficit; //summation of all deficits, for money



//***************************************************************************************************************************************************//

//Validation for another bus to be compute and added
//Loop Incase users input invalid character
        for(validation=1;validation>0;){
    printf("Do You want to add another bus for Computation?\n");
    printf("Enter 1 if Yes other wise Enter 2 if No\n");
    printf("Your Choice: "); scanf("%1d",&choices);

    switch(choices){ //this will validate the choice
        case 1: // another bus will be added
        printf("**********************************************************************************************************************\n");
        validation-=1; //terminates the loop not the program
        break; // proceeds to case 2 and will not proceed to case 2 even conditions are met

        //******************************************************
            case 2: //No bus is added calculations of the overall will be inputted and outputted
                  gain_loss=total_savings-total_deficit; //overall gain and loss, will print "-" sign if its loss
                    average_km=total_ave_km/bus; //average km//l of all buses
                average_miles=average_km/1.609; //average converted into gallons
      printf("**********************************************************************************************************************\n");
     printf("Overall average Kilometers/Liters for a week of each bus: %.2f\n",average_km);
      printf("Overall average Miles/Gallons for a week of each bus: %.2f\n",average_miles);
      printf("Overall Savings this week: %.2f liter or %.2f gallons of gasoline which cost PHP %.2f\n",total_gasoline_savings_liters,
             total_gasoline_savings_gallons,total_savings);

    printf("Overall Deficit this week: %.2f liter or %.2f gallons of gasoline which cost PHP %.2f\n",total_gasoline_deficit_liters,
             total_gasoline_deficit_gallons,total_deficit);

        printf("Overall savings or loss this week is:PHP %.2f\n",gain_loss);
        printf("**********************************************************************************************************************\n");
             return 0;//terminates the program since nothing is added and the transaction is finished
             break;//not needed tho because program terminates but just for uniformality

       //****************************************************

            default://will loop because invalid characters are inputted, not the program but just the validation
                printf("Enter 1 and 2 only!!!!!\n");
                   printf("**********************************************************************************************************************\n");
    }
}

        }


}
