/**
 * @param {string[]} tokens
 * @return {number}
 */
function evalRPN(tokens) {

    if(!(tokens.length > 0) && (tokens.length <= 10_0000)) {
        console.error("Input must be within range.");
    }

    let nos = [];
    let expr;
    tokens.forEach(token => {
        /* if(Number(token) !== 'NaN') {
            nos.push(Number(token));
        }
        else    // eval token
        {*/
            // let b = nos.pop();
            // let a = nos.pop();
            // let a = nos[nos.length - 2];
            // let b = nos[nos.length - 1];
            // nos.

            switch(token) {
                case '+':
                    nos.push(nos.pop() + nos.pop());
					// console.info("No is " + nos[0]);
                    break;
                case '-':
                    nos.push(nos.pop() - nos.pop());
                    break;
                case '*':
                    nos.push(nos.pop() * nos.pop());
                    break;
                case '/':
                    nos.push(nos.pop() / nos.pop());
                    break;
				default: 
					nos.push(Number(token));
            }
        // }
    });

    return nos[0];
};

console.info("Result is " + evalRPN(["2","1","+","3","*"]));
