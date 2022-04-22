#ifndef PROJECT_INCLUDE_DEFINES_H_  // вынести константы в enum
#define PROJECT_INCLUDE_DEFINES_H_

#define filename_for_customer_data "record.dat"
#define filename_for_transfer_data "transaction.dat"
#define filename_for_database "blackrecord.dat"

enum cases {
    case_record_cliend_data = 1,
    case_record_transfer_data,
    case_update_database
};

#define NameSizeCustomer 20
#define SurnameSizeCustomer 20
#define AddressSizeCustomer 30
#define TelNumberSizeCustomer 15

#define customer_fields_amount 8
#define transfer_fields_amount 2

typedef struct my_data {
    int number;
    char name[NameSizeCustomer];
    char surname[SurnameSizeCustomer];
    char address[AddressSizeCustomer];
    char tel_number[TelNumberSizeCustomer];
    double indebtedness;
    double credit_limit;
    double cash_payments;
} my_data;

#endif  // PROJECT_INCLUDE_DEFINES_H_
