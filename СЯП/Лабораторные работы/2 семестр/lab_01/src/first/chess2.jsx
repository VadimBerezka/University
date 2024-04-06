import './chess2.css'
export const MyChess = () => {
    const letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']
    const numbers = ['1', '2', '3', '4', '5', '6', '7', '8']

    const board = []

    for (let j = numbers.length - 1; j >= 0; j--) {
        for (let i = 0; i < letters.length; i++) {
            const color = (i + j) % 2 === 0 ? 'dark' : 'light'
            board.push(
                <div className={`chessCell ${color}`}>
                    
                </div>
            )
        }
    }

    return (
        <div className='myChess'>
            
            <div className='chessLetters'>
                {letters.map((letter, index) => (
                    <div key={index}>{letter}</div>
                ))}
            </div>

        <div className='chessBoardContainer'>

            <div className="chessNumbers">
                {numbers.map((number, index) => (
                    <div key={index}>{number}</div>
                ))}
            </div>


            <div className="chessBoard">{board}
            </div>
            

            <div className="chessNumbers">
                {numbers.map((number, index) => (
                    <div key={index}>{number}</div>
                ))}
            </div>

        </div>

            <div className='chessLetters'>
                {letters.map((letter, index) => (
                    <div key={index}>{letter}</div>
                ))}
            </div>
            
            
        </div>
    )
}

