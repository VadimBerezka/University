import React, { useState } from 'react'
import "../first/style2.css"
const EmailForm = () => {
  const [email, setEmail] = useState('')
  const [status, setStatus] = useState('')

  const handleFormSubmit = (event) => {
    event.preventDefault()

    const isValidEmail = /^[^\s@]+@[^\s@]+\.[^\s@]+$/.test(email)

    if (isValidEmail) {
      setStatus('Ваше письмо отправлено.')
    }
  }

  return (
    <div>
      <form onSubmit={handleFormSubmit}>
        <label>
          <input
            value={email}
            onChange={(event) => setEmail(event.target.value)}
            required
          />
        </label>
        <button type="submit">Отправить</button>
      </form>
      {status && <p>{status}</p>}
    </div>
  )
}

export default EmailForm