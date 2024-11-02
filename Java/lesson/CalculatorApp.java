package lesson;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Stack;

public class CalculatorApp extends JFrame {
    private JTextField display; // 显示屏

    public CalculatorApp() {
        // 设置窗口标题
        super("简单计算器");

        // 创建一个主面板，使用 BorderLayout
        JPanel mainPanel = new JPanel(new BorderLayout());

        // 创建显示屏，并添加到主面板的顶部
        display = new JTextField();
        display.setEditable(false);
        display.setFont(new Font("Arial", Font.BOLD, 48));
        display.setHorizontalAlignment(JTextField.RIGHT);
        mainPanel.add(display, BorderLayout.NORTH);

        // 创建按钮面板，使用 GridLayout 4 行 3 列
        JPanel buttonPanel = new JPanel(new GridLayout(4, 5, 4, 4));

        // 按钮数组，用于创建按钮
        String[] buttons = {
                "7", "8", "9", "+", "<",
                "4", "5", "6", "-", "(",
                "1", "2", "3", "*", ")",
                "C", "0", ".", "/", "="
        };

        // 添加按钮到按钮面板
        for (String text : buttons) {
            JButton button = new JButton(text);
            button.setFont(new Font("Arial", Font.PLAIN, 20));
            button.addActionListener(new ButtonClickListener());
            buttonPanel.add(button);
        }

        // 将按钮面板添加到主面板的中央
        mainPanel.add(buttonPanel, BorderLayout.CENTER);

        // 添加主面板到 JFrame
        add(mainPanel);

        // 设置窗口大小和默认关闭操作
        setSize(300, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null); // 窗口居中显示
    }

    // 按钮点击事件监听器
    private class ButtonClickListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            String command = ((JButton) e.getSource()).getText();

            // 根据按钮文本执行不同操作
            switch (command) {
                case "C":
                    display.setText("");
                    break;
                case ".":
                    addDecimalPoint();
                    break;
                case "=":
                    culRes();
                    break;
                case "<":
                    backspace();
                    break;
                default:
                    addDigit(command);
                    break;
            }
        }

        // 计算
        private void culRes() {
            String currentext = display.getText();
            if (!currentext.isEmpty()) {
                try {
                    display.setText(Double.toString(eval(currentext)));
                } catch (Exception ex) {
                    display.setText("Error");
                }

            }
        }

        // 退格
        private void backspace() {
            String currentext = display.getText();
            if (!currentext.isEmpty()) {
                display.setText(currentext.substring(0, currentext.length() - 1));
            }
        }

        // 添加数字到显示屏
        private void addDigit(String digit) {
            display.setText(display.getText() + digit);
        }

        // 添加小数点
        private void addDecimalPoint() {
            String currentText = display.getText();
            if (!currentText.contains(".")) {
                display.setText(currentText + ".");
            }
        }

        // 计算部分逻辑
        public static double eval(String expression) {
            if (!checkExpression(expression)) {
                throw new IllegalArgumentException("Invalid expression: " + expression);
            }
            Stack<Double> numbers = new Stack<>();
            Stack<Character> operators = new Stack<>();
            int i = 0;
            while (i < expression.length()) {
                char ch = expression.charAt(i);
                // 忽略空格
                if (Character.isWhitespace(ch)) {
                    i++;
                    continue;
                }
                if (!(Character.isDigit(ch) || ch == '(' || ch == '-' || ch == '+' || ch == '*' || ch == '/')) {
                    throw new IllegalArgumentException("Invalid character: " + ch);
                }
                // 处理负号或数字
                if (ch == '-'
                        && (i == 0 || expression.charAt(i - 1) == '(' || isOperator(expression.charAt(i - 1)))) {
                    // 处理负数
                    StringBuilder sb = new StringBuilder("-");
                    i++;
                    while (i < expression.length()
                            && (Character.isDigit(expression.charAt(i)) || expression.charAt(i) == '.')) {
                        sb.append(expression.charAt(i++));
                    }
                    numbers.push(Double.parseDouble(sb.toString()));
                    continue;
                } else if (Character.isDigit(ch) || ch == '.') {
                    // 处理正数
                    StringBuilder sb = new StringBuilder();
                    while (i < expression.length()
                            && (Character.isDigit(expression.charAt(i)) || expression.charAt(i) == '.')) {
                        sb.append(expression.charAt(i++));
                    }
                    numbers.push(Double.parseDouble(sb.toString()));
                    continue;
                }

                // 处理左括号
                if (ch == '(') {
                    operators.push(ch);
                }
                // 处理右括号并计算
                else if (ch == ')') {
                    while (operators.peek() != '(') {
                        calculateTop(numbers, operators);
                    }
                    operators.pop(); // 弹出左括号
                }
                // 处理运算符
                else if (isOperator(ch)) {
                    while (!operators.isEmpty() && precedence(operators.peek()) >= precedence(ch)) {
                        calculateTop(numbers, operators);
                    }
                    operators.push(ch);
                }
                i++;
            }
            // 计算剩余操作符
            while (!operators.isEmpty()) {
                calculateTop(numbers, operators);
            }
            // 最终结果
            return numbers.pop();
        }

        // 判断是否为运算符
        private static boolean isOperator(char ch) {
            return ch == '+' || ch == '-' || ch == '*' || ch == '/';
        }

        // 获取运算符优先级
        private static int precedence(char operator) {
            switch (operator) {
                case '+':
                case '-':
                    return 1;
                case '*':
                case '/':
                    return 2;
                default:
                    return -1;
            }
        }

        // 计算栈顶的运算符与操作数
        private static void calculateTop(Stack<Double> numbers, Stack<Character> operators) {
            if (numbers.size() < 2)
                return;
            double b = numbers.pop();
            double a = numbers.pop();
            char op = operators.pop();
            switch (op) {
                case '+':
                    numbers.push(a + b);
                    break;
                case '-':
                    numbers.push(a - b);
                    break;
                case '*':
                    numbers.push(a * b);
                    break;
                case '/':
                    numbers.push(a / b);
                    break;
            }
        }

        private static boolean checkExpression(String expression) {
            int bracketCount = 0;
            boolean lastWasOperator = true; // 标记是否可以为负号
            boolean hasNumber = false; // 检查是否至少有一个数字

            for (int i = 0; i < expression.length(); i++) {
                char ch = expression.charAt(i);

                if (Character.isWhitespace(ch)) {
                    continue; // 忽略空格
                }

                // 检查括号匹配
                if (ch == '(') {
                    bracketCount++;
                    lastWasOperator = true; // 括号后可以是负号或数字
                } else if (ch == ')') {
                    bracketCount--;
                    if (bracketCount < 0)
                        return false; // 右括号多于左括号
                    lastWasOperator = false;
                }
                // 检查数字
                else if (Character.isDigit(ch) || ch == '.') {
                    hasNumber = true;
                    lastWasOperator = false;
                }
                // 检查负号或操作符
                else if (isOperator(ch)) {
                    // 负号作为负数的符号时：应出现在表达式开头、左括号后或其他操作符后
                    if (ch == '-' && lastWasOperator) {
                        lastWasOperator = false; // 标记负号后的位置需要数字
                    }
                    // 其他操作符的处理
                    else if (lastWasOperator) {
                        return false; // 如果是连续操作符，则表达式无效
                    } else {
                        lastWasOperator = true;
                    }
                }
                // 检查非有效字符
                else {
                    return false;
                }
            }

            // 检查括号是否闭合、表达式是否以操作符结尾，以及至少有一个数字
            return bracketCount == 0 && !lastWasOperator && hasNumber;
        }

    }

    public static void main(String[] args) {
        // 创建并显示窗口
        SwingUtilities.invokeLater(() -> {
            new CalculatorApp().setVisible(true);
        });
    }
}
