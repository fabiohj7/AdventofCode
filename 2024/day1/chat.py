import numpy as np
from manimlib import *


class Part1(Scene):

    def construct(self):
        # Intro Text
        intro_words = Text("Find the locations you will visit!")
        intro_words.to_edge(UP)

        self.play(Write(intro_words))
        self.wait(1.5)
        self.play(FadeOut(intro_words))

        # Grid setup
        rows, cols = 6, 2
        numbers = [[3, 4, 2, 1, 3, 3], [4, 3, 5, 3, 9, 3]]
        number_objects = []  # Store Tex objects for numbers

        # Create numbers directly and position them
        for row in range(rows):
            row_objects = []
            for col in range(cols):
                number = Tex(f"{numbers[col][row]}", font_size=24)
                number.move_to(np.array([col - cols // 2, rows // 2 - row, 0]))
                row_objects.append(number)
                self.add(number)  # Add directly to the scene
            number_objects.append(row_objects)

        self.wait(1.5)

        # Find minimum numbers and highlight them
        # Column 0
        min_idx_0 = numbers[0].index(min(numbers[0]))
        min_number_0 = number_objects[min_idx_0][
            0]  # Number at column 0, min row
        self.play(min_number_0.animate.set_color(RED))
        self.wait(1)

        # Column 1
        min_idx_1 = numbers[1].index(min(numbers[1]))
        min_number_1 = number_objects[min_idx_1][
            1]  # Number at column 1, min row
        self.play(min_number_1.animate.set_color(RED))
        self.wait(1)
