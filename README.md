DESCRIPTION:
•	-This C++ program is a simple login and authentication system that allows users to create accounts, login, list all accounts, search for accounts by name, modify account details, change passwords, and delete accounts.
•	The program consists of several classes (login_system, CreateAcc, LoginPage, ListAccount, SearchAccount) that handle different functionalities of the system.
•	Users can create accounts by providing a unique username, contact details, email address, and date of birth. Password creation is also included with basic validation.
•	Authentication is done through a login page where users enter their username and password. The system verifies the credentials against the stored data.
•	Users can view their account details, modify account information, change passwords, and delete their accounts.
•	The program uses file handling to store user data persistently.

UNIQUE FEATURES:

1. Password Masking: When users enter their password, it's masked with asterisks for privacy and security. This feature enhances the confidentiality of user credentials.

2. Account Creation with Unique Details: When creating an account, the system checks if the entered username, phone number, and email address are unique. If not, it prompts the user to enter different details, ensuring data integrity.

3. Regex Validation for Email and Phone: Regular expressions are used to validate email addresses and phone numbers entered during account creation. This ensures that the provided data follows the correct format.

4. Delayed Output for Visual Appeal: Throughout the application, delays are introduced between actions, providing a smoother user experience. For example, when verifying user data during login or waiting for actions to complete, a delay is implemented. This adds a sense of interaction and responsiveness to the application.

5. Secure Password Change: Users can change their passwords securely by entering their old password and then confirming the new one. This prevents unauthorized password changes and ensures user account security.

6. Account Deletion Confirmation: When a user requests to delete their account, the application prompts for confirmation to prevent accidental deletions. This adds an extra layer of protection against data loss.
