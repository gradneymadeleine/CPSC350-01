#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <time.h>
using namespace std;


int main(int argc, char const *argv[]) {
  srand( time(NULL)); // reset rand


  bool loop = true; // for another file
  string filename;
  string line;

  ifstream inFile; // open file
  ofstream myfile; //creating output file stream

  if(argc > 1)
  {
    filename = argv[1];
  }

  inFile.open(filename);
  if (!inFile)
  { //check if file is there
    cout << "Unable to open file. Does not exist";
    exit(1);
  }
  else {
    cout << "Opened file: \n" << filename << endl;
  }


  string strUpper; //to change uppercase into lowercase (could not figure out tolower())
  while(getline(inFile, line))
  {
    for(char c:line)
    {
      if(c=='a')
      {
        strUpper += "A";
      }
      else if(c=='t')
      {
        strUpper += "T";
      }
      else if(c=='c')
      {
        strUpper += "C";
      }
      else if(c=='g')
      {
        strUpper += "G";
      }
      else
      {
        strUpper += c;
      }
    }
    strUpper += "\n";
  }
 inFile.close();

 myfile.open(filename); //output file
 myfile << strUpper;
 myfile.close();

while(loop){
  int total_length = 0;
  int line_number = 0;
  int num_of_aa =0;
  int num_of_at =0;
  int num_of_ac =0;
  int num_of_ag =0;
  int num_of_ta =0;
  int num_of_tt =0;
  int num_of_tc =0;
  int num_of_tg =0;
  int num_of_ca =0;
  int num_of_ct =0;
  int num_of_cc =0;
  int num_of_cg =0;
  int num_of_ga =0;
  int num_of_gt =0;
  int num_of_gc =0;
  int num_of_gg =0;
  int total_pair;
  int num_of_a = 0;
  int num_of_t = 0;
  int num_of_c = 0;
  int num_of_g = 0;
  inFile.open(filename);

      while(std::getline(inFile, line))
      { //reads file line by line
        cout << "hello " << endl;
        total_length += line.length();
        line_number++;

      }
      double mean = total_length/(double)line_number; //mean

      inFile.close(); //need to reread an go back to top of file
      inFile.open(filename);
      double difference_sq = 0.0; //line - mean
      while(std::getline(inFile, line))
      { //reads file line by line
        int line_length = line.length();

        double difference = (line_length-mean)*(line_length-mean); //length of line - the mean for variance

        difference_sq += difference;

      }
      inFile.close();
      inFile.open(filename);
      double variance = difference_sq/line_number; //variance
      double stan_dev = sqrt(variance); //standard deviation


      while(std::getline(inFile, line)){
        int line_length = line.length();
        for(int i=0; i<line_length;++i){
          //go through file to get a
          if (line[i] =='a'){
            num_of_a++;
          }
          else if (line[i] == 't'){
            num_of_t++;
          }
          else if (line[i] == 'c'){
            num_of_c++;
          }
          else if (line[i] == 'g'){
            num_of_g++;
          }
         }

      }
      
      double prob_a = num_of_a/(double)total_length;
      double prob_t = num_of_t/(double)total_length;
      double prob_c = num_of_c/(double)total_length;
      double prob_g = num_of_g/(double)total_length;

    //the need file to reread in order to get the probability of nucelotides
      inFile.close();

      inFile.open(filename);

      while(std::getline(inFile, line))
      {
        //probability of nucelotides
        int line_length = line.length();
        total_pair += line_length/2; // need total pair to include odd but it's a string
        if (line_length%2==1){//in order to see if it is even or odd
            line = line.substr(0, line.length()-1); // need to take last char off if line is odd
        }
        for(int j=0; j<line_length;j+=2){ //need it to read 2,4,6 not 1,3,5
          if(line[j] == 'a' && line[j+1] == 'a'){ // j accounts for 1 letter, j+1 is next in line
            num_of_aa++;
          }
          else if(line[j] == 'a' && line[j+1] == 't'){
            num_of_at++;
          }
          else if(line[j] == 'a' && line[j+1] == 'c'){
            num_of_ac++;
          }
          else if(line[j] == 'a' && line[j+1] == 'g'){
            num_of_ag++;
          }
          else if(line[j] == 't' && line[j+1] == 'a'){
            num_of_ta++;
          }
          else if(line[j] == 't' && line[j+1] == 'a'){
            num_of_ta++;
          }
          else if(line[j] == 't' && line[j+1] == 't'){
            num_of_tt++;
          }
          else if(line[j] == 't' && line[j+1] == 'c'){
            num_of_tc++;
          }
          else if(line[j] == 't' && line[j+1] == 'g'){
            num_of_tg++;
          }
          else if(line[j] == 'c' && line[j+1] == 'a'){
            num_of_ca++;
          }
          else if(line[j] == 'c' && line[j+1] == 't'){
            num_of_ct++;
          }
          else if(line[j] == 'c' && line[j+1] == 'c'){
            num_of_cc++;
          }
          else if(line[j] == 'c' && line[j+1] == 'g'){
            num_of_cg++;
          }
          else if(line[j] == 'g' && line[j+1] == 'a'){
            num_of_ga++;
          }
          else if(line[j] == 'g' && line[j+1] == 't'){
            num_of_gt++;
          }
          else if(line[j] == 'g' && line[j+1] == 'c'){
            num_of_gc++;
          }
          else if(line[j] == 'g' && line[j+1] == 'g'){
            num_of_gg++;
          }
      }
    }








    double prob_aa = num_of_aa/(double)total_pair;
    double prob_at = num_of_at/(double)total_pair;
    double prob_ac = num_of_ac/(double)total_pair;
    double prob_ag = num_of_ag/(double)total_pair;
    double prob_ta = num_of_ta/(double)total_pair;
    double prob_tt = num_of_tt/(double)total_pair;
    double prob_tc = num_of_tc/(double)total_pair;
    double prob_tg = num_of_tg/(double)total_pair;
    double prob_ca = num_of_ca/(double)total_pair;
    double prob_ct = num_of_ct/(double)total_pair;
    double prob_cc = num_of_cc/(double)total_pair;
    double prob_cg = num_of_cg/(double)total_pair;
    double prob_ga = num_of_ga/(double)total_pair;
    double prob_gt = num_of_gt/(double)total_pair;
    double prob_gc = num_of_gc/(double)total_pair;
    double prob_gg = num_of_gg/(double)total_pair;


    cout << "Sum: " << total_length << endl;
    cout << "Mean: " << mean << endl;
    cout << "Variance: " << variance << endl;
    cout << "Standard Deviation: " << stan_dev << endl;
    cout << "Probability of A: " << prob_a << endl;
    cout << "Probability of T: " << prob_t << endl;
    cout << "Probability of C: " << prob_c << endl;
    cout << "Probability of G: " << prob_g << endl;
    cout << "Probability of AA: " << prob_aa << endl;
    cout << "Probability of AT: " << prob_at << endl;
    cout << "Probability of AC: " << prob_ac << endl;
    cout << "Probability of AG: " << prob_ag << endl;
    cout << "Probability of TA: " << prob_ta << endl;
    cout << "Probability of TT: " << prob_tt << endl;
    cout << "Probability of TC: " << prob_tc << endl;
    cout << "Probability of TG: " << prob_tg << endl;
    cout << "Probability of CA: " << prob_ca << endl;
    cout << "Probability of CT: " << prob_ct << endl;
    cout << "Probability of CC: " << prob_cc << endl;
    cout << "Probability of CG: " << prob_cg << endl;
    cout << "Probability of GA: " << prob_ga << endl;
    cout << "Probability of GT: " << prob_gt << endl;
    cout << "Probability of GC: " << prob_gc << endl;
    cout << "Probability of GG: " << prob_gg << endl;




    inFile.close();

    myfile.open("MadeleineGradney.out"); //open file in output mode and append mode
    myfile << "Name: Madeleine Gradney\n";
    myfile << "Student ID: 0022\n";
    myfile << "gradney@chapman.edu\n";
    myfile << "CPSC 350-01\n\n\n";

    myfile << "Sum: " <<total_length << "\n";
    myfile << "Mean: " << mean << "\n";
    myfile << "Variance: " << variance << "\n";
    myfile << "Standard Deviation: " << stan_dev << "\n\n\n";
    myfile << "Probability of A: " << prob_a << "\n";
    myfile << "Probability of T: " << prob_t << "\n";
    myfile << "Probability of C: " << prob_c << "\n";
    myfile << "Probability of G: " << prob_g << "\n\n\n";
    myfile << "Probability of AA: " << prob_aa << "\n";
    myfile << "Probability of AT: " << prob_at << "\n";
    myfile << "Probability of AC: " << prob_ac << "\n";
    myfile << "Probability of AG: " << prob_ag << "\n";
    myfile << "Probability of TA: " << prob_ta << "\n";
    myfile << "Probability of TT: " << prob_tt << "\n";
    myfile << "Probability of TC: " << prob_tc << "\n";
    myfile << "Probability of TG: " << prob_tg << "\n";
    myfile << "Probability of CA: " << prob_ca << "\n";
    myfile << "Probability of CT: " << prob_ct << "\n";
    myfile << "Probability of CC: " << prob_cc << "\n";
    myfile << "Probability of CG: " << prob_cg << "\n";
    myfile << "Probability of GA: " << prob_ga << "\n";
    myfile << "Probability of GT: " << prob_gt << "\n";
    myfile << "Probability of GC: " << prob_gc << "\n";
    myfile << "Probability of GG: " << prob_gg << "\n";
  //Gaussian distribution
  inFile.open(filename);
  srand( time(NULL));
  string dnaLine = ""; // blank string for 1000 dna
  for (int k =0; k <1000; k++){
    double a = rand()/(double)RAND_MAX;
    double b = rand()/(double)RAND_MAX;
    double C = sqrt(-2 * log(a))*cos(2*M_PI*b);
    double D = stan_dev + C + mean;
    D = round(D);

    char prevLetter; //use previous letter to base next one

    if(a>=0 && a<.25){
      dnaLine+='A';
      prevLetter = 'A';
    }
    else if(a>=.25 && a<.50){
      dnaLine += 'T';
      prevLetter = 'T';
    }
    else if(a>= .50 && a<.75){
      dnaLine+= 'C';
      prevLetter = 'C';
    }
    else if(a>=.75 && a<1){
      dnaLine+= 'G';
      prevLetter = 'G';
    }

    //cout << "First letter: " << dnaLine <<endl;
    // need to take into account the length D, then give the first letter a pair
    for(int l=0; l<D-1; l++){ //the frequency of the dna
      if(prevLetter == 'A'){
        int sumAs = num_of_aa + num_of_at +num_of_ac + num_of_ag;
        double freq_aa = double(num_of_aa)/sumAs;
        double freq_at = double(num_of_at)/sumAs;
        double freq_ac = double(num_of_ac)/sumAs;
        double freq_ag = double(num_of_ag)/sumAs;
        //if(b>=0 && b<.25){
          if(b< freq_aa){
          dnaLine += 'A';
          prevLetter = 'A';
        }
      //}
      //else if (b>=.25 && b<.50){
        if(b<freq_at+ freq_aa){
          dnaLine += 'T';
          prevLetter = 'T';
        }
    //}
  //  else if(b>=.50 && b<.75){
    else  if(b< freq_aa+ freq_at+ freq_ac){
        dnaLine += 'C';
        prevLetter = 'C';
      }
    //}
    //else if(b>=.75 && b<1){
      else if(b< freq_aa + freq_at + freq_ac + freq_ag ){
        dnaLine += 'G';
        prevLetter = 'G';
      }
    //}
    }
      if(prevLetter == 'T'){
        int sumTs = num_of_ta + num_of_tt+ num_of_tc+ num_of_tg;
        double freq_ta = double(num_of_ta)/sumTs;
        double freq_tt = double(num_of_tt)/sumTs;
        double freq_tc = double(num_of_tc)/sumTs;
        double freq_tg = double(num_of_tg)/sumTs;
        //if(b>=0 && b<.25){
          if(b< freq_ta){
            dnaLine += 'A';
            prevLetter = 'A';
          }
      //  }
        //else if (b>=.25 && b<.50){
        else  if(b< freq_tt + freq_ta){
            dnaLine += 'T';
            prevLetter = 'T';
          }
        //}
      //  else if(b>=.50 && b<.75){
        else if(b<freq_tc+ freq_ta +freq_tt){
            dnaLine += 'C';
            prevLetter = 'C';
          }
        //}
        //else if(b>=.75 && b<1){
          else if(b< freq_tg+ freq_ta +freq_tt+freq_tc){
            dnaLine += 'G';
            prevLetter = 'G';
          }
        //}
      }
      if(prevLetter == 'C'){
        int sumCs = num_of_ca + num_of_ct + num_of_cc +num_of_cg;
        double freq_ca = double(num_of_ca)/sumCs;
        double freq_ct = double(num_of_ct)/sumCs;
        double freq_cc = double(num_of_cc)/sumCs;
        double freq_cg = double(num_of_cg)/sumCs;
      //  if(b>=0 && b<.25){
          if(b< freq_ca ){
            dnaLine += 'A';
            prevLetter = 'A';
          }
      //  }
        //else if (b>=.25 && b<.50){
          else if(b< freq_ct +freq_ca  ){
            dnaLine += 'T';
            prevLetter = 'T';
          }
        //}
        //else if(b>=.50 && b<.75){
        else  if(b<freq_cc + freq_ct + freq_ca){
            dnaLine += 'C';
            prevLetter = 'C';
          }
        //}
        //else if(b>=.75 && b<1){
        else  if(b <freq_cg +freq_ca +freq_ct + freq_cc){
            dnaLine += 'G';
            prevLetter = 'G';
          }
        //}

      }
      if(prevLetter == 'G'){
        int sumGs = num_of_ga + num_of_gt +num_of_gc +num_of_gg;
        double freq_ga = double(num_of_ga)/sumGs;
        double freq_gt = double(num_of_gt)/sumGs;
        double freq_gc = double(num_of_gc)/sumGs;
        double freq_gg = double(num_of_gg)/sumGs;
        //if(b>=0 && b<.25){
          if(b< freq_ga){
            dnaLine += 'A';
            prevLetter = 'A';
          }
        //}
        //else if (b>=.25 && b<.50){
        else if(b<freq_gt + freq_ga){
            dnaLine += 'T';
            prevLetter = 'T';
          }
        //}
        //else if(b>=.50 && b<.75){
        else if(b<freq_gc + freq_ga + freq_gt){
            dnaLine += 'C';
            prevLetter = 'C';
          }
        //}
      //  else if(b>=.75 && b<1){
         if(b<freq_gg + freq_ga + freq_gt + freq_gc){
            dnaLine += 'G';
            prevLetter = 'G';
          }
        //}
      }
    }
    dnaLine += "\n";
  }
  inFile.close();
  cout << "DNA LINE: " << dnaLine << endl;
  //cout << "previous letter: " << prevLetter << endl;
  //cout << "a: " << a << endl;
  //cout << "b: " << b << endl;
  ofstream txtfile;
  myfile.open("MadeleineGradney.out");
  // txtfile << "DNA Trees 4Ever!: " << dnaLine << "\n";
  myfile<< dnaLine;

  cout <<" Do you want to put in another file? (y/n)" << endl;
  char input;
  cin >> input;
  if(input == 'y' || input == 'Y'){
    cout << "Input file name: " <<endl;
    cin >> filename;
  }
  else{
    loop = false;
    exit(EXIT_SUCCESS);
    return 0;
  }

}
}
