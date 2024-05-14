import { useState } from 'react'
import { useForm } from 'react-hook-form'
import './ContactForm.css'

export const ContactForm = () => {
    const { register, handleSubmit, reset, formState: { errors } } = useForm({ mode: 'onBlur' })
    const [contacts, setContacts] = useState([])

    const onSubmit = data => {
        setContacts([...contacts, { id: Date.now(), name: data.name, email: data.email, message: data.message, gender: data.gender }])
        reset()
    }
console.log (register('name', {
    required: 'Заполни!'
}))
    return (
        <div className='container'>
            <form onSubmit={handleSubmit(onSubmit)}>
                <h2>Contact</h2>

                <div className='inputContainer'>
                    <div>Name:</div>
                    <input
                        {...register('name', {
                            required: 'Заполни!'
                        })}
                        placeholder='Enter...'
                    />
                    <div className='errorContainer'>{errors?.name && <p>{errors?.name?.message}</p>}</div>
                </div>

                <div className='inputContainer'>
                    <div>Email:</div>
                    <input
                        {...register('email', {
                            required: 'Заполни!',
                            pattern: {
                                value: /\S+@\S+\.\S+/,
                                message: 'НЕПРАВИЛЬНО!'
                            }
                        })}
                        placeholder='Enter...'
                    />
                    <div className='errorContainer'>{errors?.email && <p>{errors?.email?.message}</p>} </div>
                </div>

                <div className='inputContainer'>
                    <div>Message:</div>
                    <input
                        {...register('message', {
                            required: 'Заполни!'
                        })}
                        placeholder='Enter...'
                    />
                    <div className='errorContainer'>{errors?.message && <p>{errors?.message?.message}</p>}</div>
                </div>

                <div className="radioButtonsContainer">
                    <div className="radioButtonContainer">
                        <label>Men</label>
                        <input
                            type="radio"
                            {...register('gender', {
                                required: 'Кто ты?'
                            })}
                            value="Men"
                        />
                    </div>

                    <div className="radioButtonContainer">
                        <label>Women</label>
                        <input
                            type="radio"
                            {...register('gender', {
                                required: 'Кто ты?'
                            })}
                            value="Women"
                        />
                    </div>
                </div>

                <div className='errorContainer'>{errors?.gender && <p>{errors?.gender?.message}</p>}</div>

                <button type='submit'>Submit</button>
            </form>

            <table>
                <thead>
                    <tr>
                        <th>№</th>
                        <th>Name</th>
                        <th>Email</th>
                        <th>Message</th>
                        <th>Gender</th>
                    </tr>
                </thead>
                <tbody>
                    {contacts.map((contact, index) => (
                        <tr key={contact.id}>
                            <td>{index + 1}</td>
                            <td>{contact.name}</td>
                            <td>{contact.email}</td>
                            <td>{contact.message}</td>
                            <td>{contact.gender}</td>
                        </tr>
                    ))}
                </tbody>
            </table>
        </div>
    )
}
