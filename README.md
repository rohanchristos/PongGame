# PongGame
This is a classic Pong game developed using C++ and the raylib library. The game features an AI algorithm for automatic paddle movement, providing a challenging and engaging gameplay experience.

## Features

- Classic Pong gameplay
- AI-controlled paddle for single-player mode
- Smooth graphics and animations using raylib
- User-friendly interface
- Simple and intuitive controls

## Prerequisites

Before you begin, ensure you have met the following requirements:

- You have installed C++ (preferably GCC or any modern C++ compiler).
- You have installed [raylib](https://www.raylib.com/).
- You have a basic understanding of C++ programming.

## Installation

1. Clone the repository
    ```bash
    git clone https://github.com/rohanchristos/PongGame.git
    ```

2. Navigate to the project directory
    ```bash
    cd PongGame
    ```

3. Compile the game
    ```bash
    g++ -o pong main.cpp -lraylib
    ```

4. Run the game
    ```bash
    ./pong
    ```

## Usage

- Use the up and down arrow keys to control the player paddle.
- The AI paddle moves automatically based on the ball's position.

## AI Algorithm for Automatic Paddle Movement

The AI paddle movement is controlled by a simple algorithm that adjusts the paddle's position based on the ball's y-coordinate. Here's a brief explanation of the algorithm:

1. Calculate the difference between the ball's y-coordinate and the AI paddle's y-coordinate.
2. If the difference is positive, move the paddle down. If negative, move the paddle up.
3. Ensure the paddle stays within the screen boundaries.

## Contributing

If you want to contribute to this project, please follow these steps:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make your changes and commit them (`git commit -m 'Add some feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- [raylib](https://www.raylib.com/) for providing a simple and easy-to-use C++ game development library.
- Special thanks to all contributors and users for their valuable feedback and support.

## Contact

If you have any questions or feedback, please feel free to contact me at [your-email@example.com](mailto:your-email@example.com).

