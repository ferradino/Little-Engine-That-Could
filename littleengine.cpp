#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    // Step 1: Define variables 
    int 
        tractiveEffort, // Power of the train
        numLumber, 
        numBeams,
        numLumberFlatcars,
        numBeamFlatcars;
    
    const int
        FLATCAR_MASS = 4000, // Mass of one flatcar (kg)
        LUMBER_MASS = 1350, // Mass of one unit of lumber (kg)
        BEAM_MASS = 1410, // Mass of one unit of beam (kg)
        LUMBER_CAPACITY = 6, // Max lumber per flatcar
        BEAM_CAPACITY = 3; // Max beams per flatcar
    
    double 
        maxLoad, // Max weight the train can move 
        rulingGrade, // Slope of track
        weightOfLumber,
        weightOfBeams,
        weightOfLumberFlatcars,
        weightOfBeamFlatcars,
        weightOfFlatcars,
        weightOfLocomotive,
        weightOfConsist;
    
    const double 
        KG_TO_LBS = 2.204, // Conversion value for kg to lbs
        R1 = 0.004, // Resistance due to friction of moving parts
        R2 = 0.01; // Resistance due to incline

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

    // Validate data from user (inputs cannot be negative)
    if (weightOfLocomotive < 0 || tractiveEffort < 0 || numLumber < 0 || numBeams < 0 || rulingGrade < 0) {
        cout << "Data entered is invalid" << endl;
        return 0;
    }

    // Step 3: Calculate max load
    maxLoad = tractiveEffort / (R1 + rulingGrade * R2);
    
    // Step 4.1: Calculate weight of lumber
    weightOfLumber = numLumber * LUMBER_MASS * KG_TO_LBS;
    
    // Step 4.2: Calculate weight of beams
    weightOfBeams = numBeams * BEAM_MASS * KG_TO_LBS;
    
    // Step 4.3: Calculate weight of flatcars
    numBeamFlatcars = (numBeams + BEAM_CAPACITY - 1) / BEAM_CAPACITY; // ceil(n/d)
    numLumberFlatcars = (numLumber + LUMBER_CAPACITY - 1) / LUMBER_CAPACITY; // ceil(n/d)

    weightOfFlatcars = (numBeamFlatcars + numLumberFlatcars) * FLATCAR_MASS * KG_TO_LBS;
    
    // Step 4.4: Calculate weight of train
    weightOfConsist = weightOfLocomotive + weightOfLumber + weightOfBeams + weightOfFlatcars;

    // Step 5: Output results
    cout << endl;
    cout << setprecision(10);
    
    cout << "Number of lumber cars: " << numLumberFlatcars << endl;
    cout << "Number of beam cars: " << numBeamFlatcars << endl;
    cout << "Consist weight: " << weightOfConsist << " lbs" << endl;
    cout << "Maximum load: " << maxLoad << " lbs" << endl;
    
    // Determine whether train can carry laod
    if (weightOfConsist <= maxLoad) {
        cout << "The locomotive can move the consist along the grade" << endl;
    } else {
        cout << "The locomotive cannot move the consist along the grade" << endl;
    }
    
    return 0;

}   