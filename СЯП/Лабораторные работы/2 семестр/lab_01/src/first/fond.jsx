export const StockMarket = () => {
    const actions = [
        {
            stock_name: "EFX",
            company_name: "Equifax Inc",
            price: 163.55,
            currency: "USD",
            change: "+9.03"
        },
        {
            stock_name: "IRM",
            company_name: "Iron Mountain Inc",
            price: 33.21,
            currency: "USD",
            change: "+1.42"
        },
        {
            stock_name: "NTAP",
            company_name: "NetApp Inc",
            price: 54.81,
            currency: "USD",
            change: "-6.01"
        },
        {
            stock_name: "CTL",
            company_name: "Centurylink Inc",
            price: 13.79,
            currency: "USD",
            change: "-1.37"
        }
    ]

    return (
        <div>
            <table>

                <thead>

                    <tr>
                        <th colspan="5" style={{ border: '2px dotted' }}>Stock Market</th>
                    </tr>
                    <tr>
                        <th style={{ border: '1px solid' }}>Stock Name</th>
                        <th style={{ border: '1px solid' }}>Company Name</th>
                        <th style={{ border: '1px solid' }}>Price</th>
                        <th style={{ border: '1px solid' }}>Currency</th>
                        <th style={{ border: '1px solid' }}>Change</th>
                    </tr>
                </thead>

{/*                 <tbody>
                    <tr>
                        <td style={{ border: '1px solid' }}>EFX</td>
                        <td style={{ border: '1px solid' }}>Equifax Inc</td>
                        <td style={{ border: '1px solid' }}>163.55</td>
                        <td style={{ border: '1px solid' }}>USD</td>
                        <td style={{ border: '1px solid black', color: 'green' }}>+9.03</td>
                    </tr>
                    <tr>
                        <td style={{ border: '1px solid' }}>IRM</td>
                        <td style={{ border: '1px solid' }}>Iron Mountain Inc</td>
                        <td style={{ border: '1px solid' }}>33.21</td>
                        <td style={{ border: '1px solid' }}>USD</td>
                        <td style={{ border: '1px solid black', color: 'green' }}>+1.42</td>
                    </tr>
                    <tr>
                        <td style={{ border: '1px solid' }}>NTAP</td>
                        <td style={{ border: '1px solid' }}>NetApp Inc</td>
                        <td style={{ border: '1px solid' }}>54.81</td>
                        <td style={{ border: '1px solid' }}>USD</td>
                        <td style={{ border: '1px solid black', color: 'red' }}>-6.01</td>
                    </tr>
                    <tr>
                        <td style={{ border: '1px solid' }}>CTL</td>
                        <td style={{ border: '1px solid' }}>Centurylink Inc</td>
                        <td style={{ border: '1px solid' }}>13.79</td>
                        <td style={{ border: '1px solid' }}>USD</td>
                        <td style={{ border: '1px solid black', color: 'red' }}>-1.37</td>
                    </tr>
                </tbody> */}
                <tbody>
                    {actions.map(stock => (
                        <tr>
                            <td style={{ border: '1px solid' }}>{stock.stock_name}</td>
                            <td style={{ border: '1px solid' }}>{stock.company_name}</td>
                            <td style={{ border: '1px solid' }}>{stock.price}</td>
                            <td style={{ border: '1px solid' }}>{stock.currency}</td>
                            <td style={{ border: '1px solid black', color: stock.change.startsWith('+') ? 'green' : 'red' }}>{stock.change}</td>
                        </tr>
                    ))}
                </tbody>

            </table>
        </div>
    )
}