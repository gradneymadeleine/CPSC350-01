#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;



int main(int argc, char const *argv[]) {
  srand( time(NULL)); // reset rand

  ifstream inFile; //declare  variable
  inFile.open("DNATextFile.txt");  //open the text file for DNA

  if (!inFile)
  { //check if file is there
    cout << "Unable to open file. Does not exist";
    exit(1);
  }

  int total_length;
  int line_number;




  std::string line;
  while(std::getline(inFile, line))
  { //reads file line by line
    total_length += line.length();
    line_number++;



  }
double mean = total_length/(double)line_number;

  inFile.close(); //need to reread an go back to top of file
  inFile.open("DNATextFile.txt");
  double difference_sq; //line - mean
  while(std::getline(inFile, line))
  { //reads file line by line
    int line_length = line.length();

    double difference = (line_length-mean)*(line_length-mean); //length of line - the mean for variance

    difference_sq += difference;



  }
  inFile.close();
  inFile.open("DNATextFile.txt");
  double variance = difference_sq/line_number; //variance
  double stan_dev = sqrt(variance); //standard deviation
  
  int num_of_a = 0;
  int num_of_t = 0;
  int num_of_c = 0;
  int num_of_g = 0;
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

  inFile.open("DNATextFile.txt");
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
  while(std::getline(inFile, line)){
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
  cout << "AA" << num_of_aa << endl;
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


  cout << "Sum: " <<total_length << endl;
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

  ofstream myfile;
  myfile.open("Gradney.txt");
  myfile << "Name: Madeleine Gradney\n";
  myfile << "Student ID: 0022\n";
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

double a = rand()/(double)RAND_MAX;
double b = rand()/(double)RAND_MAX;
double C = sqrt(-2 * log(a))*cos(2*M_PI*b);
double D = stan_dev + C + mean;


cout << "a: " << a << endl;
cout << "b: " << b << endl;
cout << "C: " << C << endl;
cout << "D: " << round(D) << endl;






  return 0;
}
