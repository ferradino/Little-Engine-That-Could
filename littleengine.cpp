#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    // Step 1: Define variables 
    
    int 
        numLumber, 
        numBeams,
        numLumberFlatcars,
        numBeamFlatcars;
    
    const int
        FLATCAR_MASS = 4000,    // Mass of one flatcar (kg)
        LUMBER_MASS = 1350,     // Mass of one unit of lumber (kg)
        BEAM_MASS = 1410,       // Mass of one unit of beam (kg)
        LUMBER_CAPACITY = 6,    // Max lumber per flatcar
        BEAM_CAPACITY = 3;      // Max beams per flatcar
    
    double 
        tractiveEffort,         // Power of the train
        maxLoad,                // Max weight the train can move 
        rulingGrade,            // Slope of track
        weightOfLumber,
        weightOfBeams,
        weightOfLumberFlatcars,
        weightOfBeamFlatcars,
        weightOfFlatcars,
        weightOfLocomotive,
        weightOfConsist;
    
    const double 
        KG_TO_LBS = 2.204,      // Conversion value for kg to lbs
        R1 = 0.004,             // Resistance due to friction of moving parts
        R2 = 0.01;              // Resistance due to incline

    // Step 2: Get input from user
    
    cout << "Enter weight of locomotive (lbs): ";
    cin >> weightOfLocomotive;
    cout << "Enter tractive effort (lbf): ";
    cin >> tractiveEffort;
    
    cout << "Enter units of lumber: ";
    cin >> numLumber;
    cout << "Enter units of beams: ";
    cin >> numBeams;
    
    cout << "Enter ruling grade (2.5% = 2.5): ";
    cin >> rulingGrade;

    cout << endl;

    // Step 2.1: Validate input data from user
    
    if (weightOfLocomotive < 15000) {           // Locomotive must weight at least 15000 lbs
        cout << "Error: Locomotive weight must be at least 15000 lbs" << endl;
        cout << endl;
        return 1;

    }

    if (tractiveEffort < 2000) {                // Train must have tractive effort of at least 2000 lbf
        cout << "Error: Tractive effort must be at least 2000 lbf" << endl;
        cout << endl; 
        return 1;

    }
    
    if (numBeams < 0 || numLumber < 0) {        // Cannot have negative beams or lumber
        cout << "Error: Units of lumber and/or beams cannot be negative" << endl;
        cout << endl;
        return 1;

    }

    if (rulingGrade < 0 || rulingGrade > 10) {  // Ruling grade mostly between 0% and 10%
        cout << "Error: Ruling grade must be between 0% and 10%" << endl;
        cout << endl;
        return 1;

    }

    // Step 3: Calculate max load
    
    maxLoad = tractiveEffort / (R1 + rulingGrade * R2);
    
    // Step 4: Calculate weight of train

    // Step 4.1: Calculate weight of lumber
    
    weightOfLumber = numLumber * LUMBER_MASS * KG_TO_LBS;
    
    // Step 4.2: Calculate weight of beams
    
    weightOfBeams = numBeams * BEAM_MASS * KG_TO_LBS;
    
    // Step 4.3: Calculate weight of flatcars
    
    numBeamFlatcars = (numBeams + BEAM_CAPACITY - 1) / BEAM_CAPACITY;                    // ceil(n/d) for beam cars
    numLumberFlatcars = (numLumber + LUMBER_CAPACITY - 1) / LUMBER_CAPACITY;             // ceil(n/d) for lumber cars

    weightOfFlatcars = (numBeamFlatcars + numLumberFlatcars) * FLATCAR_MASS * KG_TO_LBS; 
    
    // Step 4.4: Calculate weight of train
    
    weightOfConsist = weightOfLocomotive + weightOfLumber + weightOfBeams + weightOfFlatcars;

    // Step 5: Output results and determine if train can carry load
    
    cout << setprecision(10);
    
    cout << "Number of lumber cars: " << numLumberFlatcars << endl;
    cout << "Number of beam cars: " << numBeamFlatcars << endl;
    cout << "Consist weight: " << weightOfConsist << " lbs" << endl;
    cout << "Maximum load: " << maxLoad << " lbs" << endl;
   
    if (weightOfConsist <= maxLoad) {   // Train can carry load
        cout << "The locomotive can move the consist along the grade" << endl;

    } else {                            // Train cannot carry load
        cout << "The locomotive cannot move the consist along the grade" << endl;

    }

    cout << endl; // Skip line after output for ease of reading in terminal window (personal preference)

    return 0;

}   