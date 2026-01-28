// PHYS30762 Programming in C++
// Assignment 2
// Student ID: 10831050, last updated 22/02/25

// Program to compute mean, standard deviation and standard
// error from list of books read from a data file. User is
// asked which category of books they would like and if they
// would like it sorted by author surname.

#include<iostream> // For std::cout, std::cin
#include<iomanip> // For std::fixed, std::setprecision
#include<fstream> // For std::fstream
#include<cmath> // For std::sqrt, std::pow
#include<string> // For std::string
#include<vector> // For std::vector
#include<utility> // For std::pair
#include<algorithm> // For std::replace

// Function to extract the surname from the full name inputted
std::string extract_surname(const std::string& full_name)
{
    std::istringstream extract(full_name);
    std::string word, surname;

    while(extract>>word)
    {
      surname = word;
    }
    return surname;
}

// Function to calculate the mean of the price data
double calculate_mean(std::vector<std::string> price_data)
{
  int number_of_values{0};
  double sum{0};
  double mean;

  for(const std::string& price : price_data)
  {
    if(!price.empty()) {number_of_values+=1; sum += std::stod(price);}
  }
  mean = (sum/number_of_values);
  return mean;
}

// Function that calculates the standard deviation and standard error from the mean
std::pair<double, double> calculate_standard_deviation_and_error(std::vector<std::string> price_data, double input_mean)
{
  int number_of_values{0};
  double sum_of_square_of_deviation{0};
  double output_standard_deviation;
  double output_standard_error;

  for(const std::string& price : price_data)
  {
    if(!price.empty()) {number_of_values+=1; sum_of_square_of_deviation += std::pow(std::stod(price)-input_mean,2);}
  }
  output_standard_deviation = std::sqrt(sum_of_square_of_deviation/(number_of_values-1));
  output_standard_error = output_standard_deviation/std::sqrt(number_of_values);
  return {output_standard_deviation, output_standard_error};
}

// Function to open data file, check it has opened successfully, and then read the data into a vector of vectors.
std::vector<std::vector<std::string>> open_and_read_data_file(std::string data_file)
{
  std::fstream book_stream(data_file);
  if(!book_stream.is_open()) {std::cerr<<"Error: file could not be opened."<<std::endl; return {};}

  std::vector<std::vector<std::string>> books_data;
  std::string line;
  while(std::getline(book_stream,line, '\n'))
  {
    std::vector<std::string> row;
    size_t pos = 0;
    std::string delimiter = "    ";
    while((pos = line.find(delimiter)) != std::string::npos) 
    {
      row.push_back(line.substr(0, pos));
      line.erase(0, pos + delimiter.length());
    }
    row.push_back(line);
    books_data.push_back(row);
  }
  book_stream.close();
  return books_data;
}

// Function to produce a vector for a specific column in the vector of vectors.
std::vector<std::string> form_column(std::vector<std::vector<std::string>> matrix, int column_index)
{
  std::vector<std::string> column;

  for(const std::vector<std::string>& i : matrix)
  {
    if(!i.empty()) {column.push_back((i)[column_index]);}
  }

  return column;
}

// Function to retrieve the subject desired by the user and convert the original list of books into a list based on the subject.
std::vector<std::vector<std::string>> retrieve_subject_based_list(std::vector<std::vector<std::string>> books_data)
{
  std::vector<std::string> subject_column{form_column(books_data,1)};
  std::vector<std::vector<std::string>> book_list;
  std::string subject_name;

  bool unsuccessful{true};

  while(unsuccessful)
  {
    int index{0};

    std::cout<<"Would you like \"All\", \"Physics\", \"Mathematics\", or \"Chemistry\" based books: ";
    std::cin>>subject_name;

    if(subject_name == "Physics" || subject_name == "Mathematics" || subject_name == "Chemistry")
    {
      for(const std::string& element : subject_column)
      {
        if(element==subject_name) {book_list.push_back(books_data[index]); index+=1;}
      }
      unsuccessful = false;
    }
    else
    {
      if(subject_name == "All")
      {
        book_list = books_data;
        unsuccessful = false;
      }
      else
      {
        std::cout<<"Invalid input. Please enter exactly from the choice of \"All\", \"Physics\", \"Mathematics\", or \"Chemistry\"."<<std::endl;
      }
    }
  }
  return book_list;
}

// Function to retrieve and perform user decision of whether to sort the list or not
std::vector<std::vector<std::string>> sort_based_on_user_decision(std::vector<std::vector<std::string>> book_list)
{
  bool unsuccessful{true};

  while(unsuccessful)
  {
    char decision;
    std::cout<<"Would you like the list of books sorted by author surname? (y/n) ";
    std::cin>>decision;
    if(decision == 'y')
    {
      std::vector<int> indicies;
      std::sort(book_list.begin(), book_list.end(), [](const std::vector<std::string>& a, const std::vector<std::string>& b)
      {
        std::string surname_a{extract_surname(a[2])};
        std::string surname_b{extract_surname(b[2])};
        return surname_a < surname_b;
      });
      unsuccessful = false;
    }
    else
    {
      if(decision == 'n')
      {
        unsuccessful = false;
      }
      std::cout<<"Invalid input. Please enter either \"y\" or \"n\""<<std::endl;
    }
  }
  return book_list;
}

// Function to print list of books using an iterator
void print_books(std::vector<std::vector<std::string>> book)
{
  if(!book.empty())
  {
    for(const std::vector<std::string> row : book)
    {
      for(const std::string element : row)
      {
        std::cout<<"| "<<element<<" |";
      }
      std::cout<<std::endl;
    }
  }
}

// Main function
int main()
{
  std::vector<std::vector<std::string>> book_matrix;
  std::vector<std::string> price_list;
  std::pair<double, double> mean_and_number, standard_deviation_and_error;
  double mean_price;
  double standard_deviation;
  double standard_error;
  std::vector<std::vector<std::string>> subject_based_list, final_list;

  book_matrix = open_and_read_data_file("books_data.dat");

  subject_based_list = retrieve_subject_based_list(book_matrix);

  final_list = sort_based_on_user_decision(subject_based_list);

  price_list = form_column(final_list,0);
  mean_price = calculate_mean(price_list);
  standard_deviation_and_error = calculate_standard_deviation_and_error(price_list, mean_price);
  standard_deviation = standard_deviation_and_error.first;
  standard_error = standard_deviation_and_error.second;

  print_books(final_list);

  std::cout<<std::fixed<<std::setprecision(2)<<" || "<<"Mean price is: £"<<mean_price<<" || "<<std::endl;
  std::cout<<std::fixed<<std::setprecision(2)<<" || "<<"Standard deviation is: £"<<standard_deviation<<" || "<<std::endl;
  std::cout<<std::fixed<<std::setprecision(2)<<" || "<<"Standard error is: £"<<standard_error<<" || "<<std::endl;

  return 0;
}
