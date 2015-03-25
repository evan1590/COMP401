$( document ).ready(function() {
    console.log( "ready!" );
    $(".change").click(function(){
        var x = $('.inputfield1').val();
        var y = $('.inputfield2').val();
        console.log(x);
        console.log(y);
        // if (y == 0) {
        // 	console.log("got you")
        // }; trying to figure out what goes wrong
        levenshteinDist(x, y);
    });
});

function levenshteinDist(string1, string2) {
    var word = string1.length;
    var newWord = string2.length;
    var matrix = [];
    var indexI; 
    var indexJ;
 
    if (word == 0) {
    	console.log(newWord);
    	alert(newWord);
    	return newWord;
    };
    
    if (newWord == 0) {
    	console.log(word);
    	alert(word);
    	return word;
    };
 
 	//first column of each row
    for (indexI = 0; indexI <= word; indexI++)
        matrix[indexI] = [indexI];
    
    // each column in first row
    for (indexJ = 0; indexJ <= newWord; indexJ++) 
        matrix[0][indexJ] = indexJ;
 	
 	// goes through and fills out the matrix
    for (indexJ = 1; indexJ <= newWord; indexJ++) {
        for (indexI = 1; indexI <= word; indexI++) {
            if (string1[indexI-1] == string2[indexJ-1]) 
                matrix[indexI][indexJ] = matrix[indexI - 1][indexJ - 1];
            else 
                matrix[indexI][indexJ] = Math.min(matrix[indexI-1][indexJ], matrix[indexI][indexJ-1], matrix[indexI-1][indexJ-1]) + 1;
        }
    }
    console.log(matrix[word][newWord]);
    alert(matrix[word][newWord]);
}
