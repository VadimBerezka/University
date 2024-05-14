import { useEffect, useState } from 'react'
import { colors } from './colors'
import './ColorPicker.css'

export const ColorPicker = () => {
    const [chosenColor, setChosenColor] = useState('')
    const [colorCollection, setColorCollection] = useState([])
    const [storedColors, setStoredColors] = useState([])

    const storeColor = () => {
        const updatedColorCollection = [...colorCollection, { id: Date.now(), color: chosenColor }]

        setColorCollection(updatedColorCollection)

        localStorage.setItem('storedColors', JSON.stringify(updatedColorCollection))
    }

    useEffect(() => {
        const storedColorsFromStorage = JSON.parse(localStorage.getItem('storedColors'))

        if (storedColorsFromStorage) {
            setStoredColors(storedColorsFromStorage)
        }
    }, [])

    return (
        <div className='container'>
            <div className='colorsContainer'>
                {colors.map(color => (
                    <div key={color.id} className='colorContainer' style={{background: color.encoding}} onClick={() => setChosenColor(color.encoding)}></div>
                ))}
            </div>

            <div className='pickerContainer'>
                <div className='colorContainer' style={{background: chosenColor}}></div>
                <div className='button' onClick={() => setChosenColor('#fff')}>Сброс</div>
                <div className='button' onClick={() => storeColor()}>Сохранить</div>
            </div>

            <div className='listContainer'>
                <table>
                    <thead>
                        <tr>
                            <th>№</th>
                            <th>Цвет</th>
                        </tr>
                    </thead>

                    <tbody>
                        {storedColors && storedColors.map((item, index) => (
                            <tr key={item.id}>
                                <td>{index + 1}</td>
                                <td><div className='colorContainer' style={{background: item.color}}></div></td>
                            </tr>
                        ))}
                    </tbody>
                </table>
            </div>
        </div>
    )
}
