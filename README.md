# Clinic Management System

This project implements a simple clinic management system in C. It allows users to manage patient data and schedule appointments efficiently.

## Features
- **Patient Management**: Add, view, and manage patient details such as name, contact information, and ID.
- **Appointment Scheduling**: Schedule and view appointments by date and time.
- **File Handling**: The system reads and writes patient data and appointment details from text files.

## Project Structure

- `Main.c`: Contains the `main()` function, which handles the program's flow.
- `clinic.c`: Implements clinic-related functionalities such as scheduling appointments and managing patients.
- `clinic.h`: Header file for the clinic module.
- `core.c`: Contains core functionalities like input handling and utility functions.
- `core.h`: Header file for the core module.
- `appointmentData.txt`: A text file storing appointment data in the format of patient ID, year, month, day, hour, and minute&#8203;:contentReference[oaicite:0]{index=0}.
- `patientData.txt`: A text file storing patient details such as ID, name, contact method, and phone number&#8203;:contentReference[oaicite:1]{index=1}.

## How to Run

1. Compile the project using a C compiler:
   ```bash
   gcc -o clinic Main.c clinic.c core.c
