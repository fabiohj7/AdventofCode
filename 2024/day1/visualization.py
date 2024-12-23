import numpy as np
from manimlib import *


class part1(Scene):

    def construct(self):
        intro_words = Text("Find the locations you will visit!")
        intro_words.to_edge(UP)

        self.play(Write(intro_words))
        self.wait(1.5)
        self.play(FadeOut(intro_words))

        rows, cols = 6, 2
        grid = VGroup()
        numbers = [[3, 4, 2, 1, 3, 3], [4, 3, 5, 3, 9, 3]]
        number_objects = []

        for row in range(rows):
            row_objects = []
            for col in range(cols):
                square = Square(side_length=1)
                square.move_to(np.array([col - cols // 2, rows // 2 - row, 0]))

                number = Tex(f"{numbers[col][row]}", font_size=36)
                number.move_to(square.get_center())

                cell = VGroup(square, number)
                row_objects.append(number)
                grid.add(cell)
            number_objects.append(row_objects)

        self.play(Write(grid))
        self.wait(1.5)
        self.play(grid.animate.to_edge(LEFT))

        ans = 0
        total = Text(f"Total: {ans}", font_size=52)
        self.play(Write(total))

        for _ in range(len(numbers[0])):
            min_idx_0 = numbers[0].index(min(numbers[0]))
            min_number_0 = number_objects[min_idx_0][0]
            self.play(min_number_0.animate.set_color(RED))
            self.wait(1)
            min_idx_1 = numbers[1].index(min(numbers[1]))
            min_number_1 = number_objects[min_idx_1][1]
            self.play(min_number_1.animate.set_color(RED))
            self.wait(1)

            ans += abs(min(numbers[0]) - min(numbers[1]))
            trans = Text(f"Total: {ans}", font_size=52)
            self.play(FadeTransform(total, trans))
            total = trans

            numbers[0][min_idx_0] = float("inf")
            numbers[1][min_idx_1] = float("inf")

            self.play(FadeOut(min_number_0), FadeOut(min_number_1))


class part2(scene):

