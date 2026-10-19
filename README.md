# minimarket-struct-pointer

Project Description

This project is a simple minimarket application built with the C programming language. It uses a command-line interface (CLI) to manage products, stock, and member points.

Features

- View the product catalog and current stock.
- Buy products and update stock automatically.
- View member names and points.
- Update product prices.
- Correct product names.
- Redeem 1,000 member points for a 10% purchase discount.
- Award 100 points when an eligible purchase reaches at least Rp20,000.
- Use an interactive menu until the user chooses to exit.

Solution Overview

The program uses `struct` types to store product and member information. Arrays hold the product and member records. Functions handle displaying information, updating product details, and processing purchases. Pointers let functions modify the original records directly. The menu uses a loop and a `switch` statement to let the user select an operation.
