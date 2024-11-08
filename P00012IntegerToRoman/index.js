/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
//	console.log(num);
	const symbolMap = {
		"1": "I",
		"5": "V",
		"10": "X",
		"50": "L",
		"100": "C",
		"500": "D",
		"1000": "M"
	};
	const knownValues = { 
		1: 'I', 2: 'II', 3: 'III', 4: 'IV', 5: 'V', 6: 'VI', 7: 'VII', 8: 'VIII', 9: 'IX', 10: 'X', 11: 'XI', 20: 'XX', 30: 'XXX', 40: 'XL', 50: 'L',
		17: 'XVII', 90: 'XC', 400: 'CD', 900: 'CM', 
		100: 'C', 500: 'D', 1000: 'M'
	}

	const symbols = [1, 5, 10, 50, 100, 500, 1000];

	if(knownValues[num]) {
		return knownValues[num];
	}


	const maxSubstract = (n) => { for(let i = symbols.length - 1; i >= 1; i--) { if(n-symbols[i]>=0) return symbols[i]; }; return symbols[0];  };

	const s = num.toString();
	const d = s[0];
	switch(d) {
		case '4':
			switch(s.length) {
				case 1:
					return `IV${intToRoman(num - 4)}`;
				case 2:
					return `XL${intToRoman(num - 40)}`;
				case 3:
					return `CD${intToRoman(num - 400)}`;
			}
			break;
		case '9':
			switch(s.length) {
				case 1:
					return `IX${intToRoman(num - 9)}`;
				case 2:
					return `XC${intToRoman(num - 90)}`;
				case 3:
					return `CM${intToRoman(num - 900)}`;
			}
			break;
		default:
			{
				const ms = maxSubstract(num);
//				console.log('mmmm', ms);
				return `${intToRoman(ms)}${intToRoman(num - ms)}`;
			}
	}
};

for(let i = 1; i< 4000; i++) {
	console.log(i);
console.log(intToRoman(i));
}
