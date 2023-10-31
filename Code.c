#include <stdio.h>
#include <stdlib.h>

// Define the structure for customer information
typedef struct customer {
  int customer_id;
  char name[50];
  char contact_number[10];
  char purchase_history[100];
  struct customer *next;
} customer;

// Define the front and rear pointers for the queue
customer *front = NULL;
customer *rear = NULL;

// Function to enqueue a customer
void enqueue(customer *new_customer) {
  if (front == NULL) {
    front = new_customer;
    rear = new_customer;
  } else {
    rear->next = new_customer;
    rear = new_customer;
  }
}

// Function to dequeue a customer
customer *dequeue() {
  if (front == NULL) {
    return NULL;
  } else {
    customer *temp = front;
    front = front->next;
    return temp;
  }
}

// Function to display the customer information for a given customer ID
void display_customer_info(customer *cust) {
  printf("Customer Name: %s\n", cust->name);
  printf("Customer Contact Number: %s\n", cust->contact_number);
  printf("Customer Purchase History: %s\n", cust->purchase_history);
}

// Function to display the customer information for a given customer ID
void display_customer_info_by_id(int customer_id) {
  customer *temp = front;

  while (temp != NULL) {
    if (temp->customer_id == customer_id) {
      display_customer_info(temp);
      return;
    }

    temp = temp->next;
  }

  printf("Customer with ID %d does not exist.\n", customer_id);
}

// Function to update the customer information for a given customer ID
void update_customer_info_by_id(int customer_id) {
  customer *temp = front;

  while (temp != NULL) {
    if (temp->customer_id == customer_id) {
      printf("Enter the new customer name: ");
      scanf("%s", temp->name);

      printf("Enter the new customer contact number: ");
      scanf("%s", temp->contact_number);

      printf("Enter the new customer purchase history: ");
      scanf("%s", temp->purchase_history);

      return;
    }

    temp = temp->next;
  }

  printf("Customer with ID %d does not exist.\n", customer_id);
}

// Function to display all customers in the queue in order
void display_all_customers() {
  customer *temp = front;

  while (temp != NULL) {
    printf("Customer ID: %d\n", temp->customer_id);
    display_customer_info(temp);

    temp = temp->next;
  }
}

// Main function
int main() {
    int choice, customer_id;
    customer *new_customer;
    customer *dequeued_customer;

    while (1) {
        printf("1. Enqueue a new customer\n");
        printf("2. Dequeue a customer\n");
        printf("3. Display customer information by ID\n");
        printf("4. Update customer information by ID\n");
        printf("5. Display all customers in order\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Enqueue a new customer
                new_customer = (customer *)calloc(1, sizeof(customer));
                printf("Enter the customer ID: ");
                scanf("%d", &new_customer->customer_id);

                printf("Enter the customer name: ");
                scanf("%s", new_customer->name);

                printf("Enter the customer contact number: ");
                scanf("%s", new_customer->contact_number);

                printf("Enter the customer purchase history: ");
                scanf("%s", new_customer->purchase_history);

                enqueue(new_customer);

                printf("Customer successfully enqueued.\n");
                break;

            case 2:
                // Dequeue a customer
                dequeued_customer = dequeue();

                if (dequeued_customer != NULL) {
                    printf("Customer ID: %d\n", dequeued_customer->customer_id);
                    display_customer_info(dequeued_customer);

                    free(dequeued_customer);
                } else {
                    printf("The queue is empty.\n");
                }
                break;

            case 3:
                // Display customer information by ID
                printf("Enter the customer ID: ");
                scanf("%d", &customer_id);

                display_customer_info_by_id(customer_id);
                break;

            case 4:
                // Update customer information by ID
                printf("Enter the customer ID: ");
                scanf("%d", &customer_id);

                update_customer_info_by_id(customer_id);
                break;

            case 5:
                // Display all customers in order
                display_all_customers();
                break;

            case 6:
                // Exit
                exit(0);
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}
