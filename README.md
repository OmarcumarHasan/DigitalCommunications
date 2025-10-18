# Digita_Communications-
Hello, I’m Omar a 3rd-year Computer Engineering student exploring how data is encoded, transmitted, and understood. This project showcases my journey through Digital Communications. From RLE compression and channel coding to modulation and data analysis. turning complex theory into working code.

My Understanding of the Project:

This CA will focus on designing and developing a Run-Length Encoding (RLE) compression program in C. While the task might appear straightforward at first, the real goal will be to understand how data can be represented more efficiently and how the ideas from digital communications can be applied in real programming work.

RLE will operate by checking how many times a character repeats in a sequence and then replacing that repetition with the character and the number of times it appears. For example, the text

AAAAA BB CC DD  
A5    B2 C2 D2

This reduces redundancy and helps decrease the overall data size.

In most cases, RLE is a lossless method, meaning that the original data can be perfectly reconstructed. However, in some real-world applications such as image or audio processing, modified forms of RLE may be applied in a lossy manner to achieve higher compression at the expense of detail. Understanding this distinction helped clarify that compression is not a single fixed process, but rather a design choice that balances efficiency and fidelity depending on the context.

The project also required designing the program so that input could be obtained through multiple sources — including files, standard input streams, command-line arguments, and hardcoded arrays. This flexibility encouraged a deeper understanding of how input handling works in C and how to write adaptable, modular functions that can process data regardless of its origin.

